import tkinter as tk
from tkinter import filedialog, ttk
from tkinterdnd2 import DND_FILES, TkinterDnD
import re
import os

def contar_caracteres(texto):
    # caracteres sin espacios
    sin_espacios = len(texto.replace(" ", "").replace("\n", "").replace("\t", ""))

    # solo letras y números
    solo_letras_numeros = len(re.findall(r"[A-Za-z0-9]", texto))

    return sin_espacios, solo_letras_numeros


def procesar_archivo(ruta):
    try:
        with open(ruta, "r", encoding="utf-8", errors="ignore") as f:
            contenido = f.read()

        c1, c2 = contar_caracteres(contenido)

        tabla.insert("", "end", values=(os.path.basename(ruta), c1, c2))

    except Exception as e:
        print("Error:", e)


def seleccionar_archivos():
    archivos = filedialog.askopenfilenames(
        title="Seleccionar archivos C++",
        filetypes=[("C++ files", "*.cpp *.h *.hpp"), ("Todos", "*.*")]
    )

    for archivo in archivos:
        procesar_archivo(archivo)


def drop(event):
    archivos = root.tk.splitlist(event.data)
    for archivo in archivos:
        procesar_archivo(archivo)


# ventana
root = TkinterDnD.Tk()
root.title("Contador de caracteres C++")
root.geometry("650x400")

# boton seleccionar
btn = tk.Button(root, text="Seleccionar archivos", command=seleccionar_archivos)
btn.pack(pady=10)

# area drag drop
drop_label = tk.Label(root, text="Arrastra archivos aquí", bg="#dddddd", height=3)
drop_label.pack(fill="x", padx=10, pady=10)

drop_label.drop_target_register(DND_FILES)
drop_label.dnd_bind("<<Drop>>", drop)

# tabla resultados
cols = ("Archivo", "Caracteres sin espacios", "Solo letras y números")

tabla = ttk.Treeview(root, columns=cols, show="headings")

for col in cols:
    tabla.heading(col, text=col)
    tabla.column(col, width=200)

tabla.pack(fill="both", expand=True, padx=10, pady=10)

root.mainloop()