#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

string fallback_phrases = {}"Estaba la pajara pinta, a la sombra del verde limon, con el pico picaba la rama, con las alas recoge la flor",
"Homero Simpson",
"Este problema no tiene acentos o simbolos raros del espanol a proposito",
":0 alguna vez pensaron que podria pasar si una persona absolutamente sin conocimientos de LLM se pone a querer disenar una LLM?",
"La llamariamos PLM, Pathetic Language Model.",
"Saben lo que es una LLM? Veamos la definicion segun Pepe Argento:",
"Una LLM es como una maquina que se trago medio internet, libros, pavadas, discusiones de gente al pedo y ahora te contesta como si supiera. Vos le preguntas algo y la cosa esa arma una respuesta palabra por palabra, tratando de sonar inteligente.",
"Ahora, como creamos una PLM? Y no se... pero va a ser tu trabajo al final de este problema.",
"Nuestro amigo Penguino esta creando una PLM, pero decide alimentarla de informacion absolutamente necesaria, es decir sus problemas de la OBI, algunas frases de sus series favoritas, y claro ehhh sus canciones favoritas?",
'Por ejemplo escucharon esa que dice "Por favor! te lo pido solo vete! no penses que esto es amor! yo se que nada es pa siempre!"',
"Leyeron Mafalda? Siempre me rio con esta tira:",
"¿QUE OPINAN EN TU CASA DE COMO ANDAN LAS COSAS? ¡PUF! POR LO MENOS SON OPTIMISTAS; EN LA MIA OPINAN QUE ¡PUAJ!",
"Podrian demandarme por incluir esa imagen? Ojala que no... Por cierto PARAPATINTINTIRINTIN!",
'En fin, me estoy desviando de la tematica del problema... donde estaba? Ah si! Series favoritas, ehmmm... A penguino le encanta Los simpsons, How I Met Your Mother, LOST, The office, Severance! Vieron el final de la primera temporada! QUE FINAL! "SHE IS ALIVE!"',
"Y los numeros de LOST? cuatro ocho quince dieciseis veintitres cuarenta y dos, top 6 numeros de la historia! un sinsentido monumental pero dentro de la serie encajaba, lo juro.",
"Ok, ya, PLMs... Crear una PLM es como comer una naranja.",
"Bueno, la verdad ya me aburri de redactar, es momento de revelar la verdadera identidad de Penguino: Penguino es el verdadero creador de estos problemas!!!!!!!",
"Pensaron que Penguino era Dario? No senor, Dario murio de una sobredosis de azucar el Octubre del 16.",
"Pero revivio! Ahora esta vivo.",
"Fua quisiera contar esa historia, pero que flojera seguuir redactando.",
"Ah si, una PLM agarra un texto y solo produce la siguiente palabra dependiendo de la palabra previa.",
"Basate en el contenido de este problema y como haria Penguino una PLM para hacer la tuya.",
"La entrada contiene muchas palabras, cada una en una linea. La ultima palabra es MAGUMBO.",
'Para cada palabra tu PLM debe predecir la palabra que sigue, no imprimas nada para la palabra "MAGUMBO".',
'Si no hay continuacion para la palaaabra que se te da, imprime "LOL".',
'Y si no entrenamos con esa palabrita no se... imprime "XDDDDDDD".',
'Cada caso de prueba tendra palabras de una sola linea de texto usada para entrenar a la PLM.',
'(10 puntos) Cada caso de prueba da 10 puntos, son 10 casos de prueba'
}
const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

        map<string,string> mp;
        for(auto s: vs){
            string a = "YIYIYIYIY";
            string b = "";
            for (int i = 0; i < s.size(); i++)
            {
                if(s[i] == ' '){
                    mp[a]= b;
                    a = b;
                    b = "";
                    continue;
                }
                b.push_back(s[i]);
            }
            mp[a] = b;
            a = b;
            mp[a] ="000";
        }
        
    string p;
    while(cin>>p){

        if(p == "MAGUMBO"){
            cout<<"\n";
            break;
        }else if(mp.find(p) == mp.end()){
            cout<<"XDDDDDDD \n";
        }else if(mp[p] == "000"){
            cout<<"LOL\n";
        }else{
            cout<<mp[p]<<"\n";
        }
    }


    return 0;
}




