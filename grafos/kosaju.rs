
use std::io::{self, Read};

fn dfs(
    x: usize,
    grafo: &Vec<Vec<usize>>,
    vis: &mut Vec<bool>,
    topo: &mut Vec<usize>,
) {
    let mut st = vec![(x, 0usize)];
    vis[x] = true;

    while let Some(&(ni, ind)) = st.last() {
        if ind == grafo[ni].len() {
            st.pop();
            topo.push(ni);
        } else {
            let y = grafo[ni][ind];
            st.last_mut().unwrap().1 += 1;

            if !vis[y] {
                vis[y] = true;
                st.push((y, 0));
            }
        }
    }
}

fn dfs2(
    x: usize,
    grafo: &Vec<Vec<usize>>,
    vis: &mut Vec<bool>,
    grupo: &mut Vec<usize>,
    cnt: usize,
) {
    let mut st = vec![(x, 0usize)];
    vis[x] = true;
    grupo[x] = cnt;

    while let Some(&(ni, ind)) = st.last() {
        if ind == grafo[ni].len() {
            st.pop();
        } else {
            let y = grafo[ni][ind];
            st.last_mut().unwrap().1 += 1;

            if !vis[y] {
                vis[y] = true;
                grupo[y] = cnt;
                st.push((y, 0));
            }
        }
    }
}

fn dfs3(
    x: usize,
    grafo: &Vec<Vec<usize>>,
    fafo: &Vec<Vec<usize>>,
    vis: &mut Vec<bool>,
    dp: &mut Vec<i64>,
    val: &Vec<i64>,
    pa: &mut Vec<usize>,
) {
    let mut st = vec![(x, 0usize)];
    vis[x] = true;

    while let Some(&(ni, ind)) = st.last() {
        if ind == grafo[ni].len() {
            st.pop();
            dp[ni] += val[ni];

            for &x in &fafo[ni] {
                dp[x] = dp[x].max(dp[ni]);
            }
        } else {
            let y = grafo[ni][ind];
            st.last_mut().unwrap().1 += 1;

            if !vis[y] {
                vis[y] = true;
                pa[y] = ni;
                st.push((y, 0));
            }
        }
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();

    let arr: Vec<i64> = (0..n)
        .map(|_| iter.next().unwrap().parse().unwrap())
        .collect();

    let mut grupo = vec![0usize; n];
    let mut vis = vec![false; n];

    let mut grafo = vec![Vec::<usize>::new(); n];
    let mut fafo = vec![Vec::<usize>::new(); n];
    let mut topo = Vec::new();

    for _ in 0..m {
        let a: usize = iter.next().unwrap().parse::<usize>().unwrap() - 1;
        let b: usize = iter.next().unwrap().parse::<usize>().unwrap() - 1;

        grafo[a].push(b);
        fafo[b].push(a);
    }

    for i in 0..n {
        if !vis[i] {
            dfs(i, &grafo, &mut vis, &mut topo);
        }
    }

    topo.reverse();
    vis.fill(false);

    let mut cnt = 0usize;

    for &x in &topo {
        if !vis[x] {
            cnt += 1;
            dfs2(x, &fafo, &mut vis, &mut grupo, cnt);
        }
    }

    let mut grafinho = vec![Vec::<usize>::new(); cnt];
    let mut grafinho2 = vec![Vec::<usize>::new(); cnt];

    let mut vis1 = vec![false; cnt];
    let mut val = vec![0i64; cnt];

    for i in 0..n {
        val[grupo[i] - 1] += arr[i];
    }

    for i in 0..n {
        for &x in &grafo[i] {
            if grupo[i] != grupo[x] {
                grafinho[grupo[i] - 1].push(grupo[x] - 1);
            }
        }
    }

    for vecinos in &mut grafinho {
        vecinos.sort_unstable();
        vecinos.dedup();
    }

    for i in 0..cnt {
        for &x in &grafinho[i] {
            grafinho2[x].push(i);
        }
    }

    let mut dp = vec![0i64; cnt];
    let mut pa = vec![0usize; cnt];

    for i in 0..cnt {
        if !vis1[i] {
            dfs3(
                i,
                &grafinho,
                &grafinho2,
                &mut vis1,
                &mut dp,
                &val,
                &mut pa,
            );
        }
    }

    let mut res = 0i64;

    for i in 0..cnt {
        res = res.max(dp[i]);
    }

    println!("{}", res);
}
