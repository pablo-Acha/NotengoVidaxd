import tkinter as tk

class LectorApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Práctica de Lectura (WPM)")

        # Texto de entrada
        tk.Label(root, text="Ingresa el texto:").pack()
        self.texto_input = tk.Text(root, height=10, width=60)
        self.texto_input.pack()

        # Configuración
        frame = tk.Frame(root)
        frame.pack(pady=10)

        tk.Label(frame, text="Palabras por bloque:").grid(row=0, column=0)
        self.entry_n = tk.Entry(frame, width=5)
        self.entry_n.insert(0, "3")
        self.entry_n.grid(row=0, column=1)

        tk.Label(frame, text="Palabras por minuto (WPM):").grid(row=0, column=2)
        self.entry_wpm = tk.Entry(frame, width=7)
        self.entry_wpm.insert(0, "200")
        self.entry_wpm.grid(row=0, column=3)

        # Botón iniciar
        tk.Button(root, text="Iniciar", command=self.iniciar).pack()

        # Salida
        self.label_salida = tk.Label(root, text="", font=("Arial", 20), wraplength=500)
        self.label_salida.pack(pady=20)

        self.palabras = []
        self.indice = 0

    def iniciar(self):
        texto = self.texto_input.get("1.0", tk.END).strip()
        self.palabras = texto.split()

        try:
            self.n = int(self.entry_n.get())
            wpm = int(self.entry_wpm.get())
        except:
            return

        # calcular tiempo dinámicamente
        self.tiempo = int((self.n / wpm) * 60000)

        self.indice = 0
        self.mostrar_bloque()

    def mostrar_bloque(self):
        if self.indice >= len(self.palabras):
            self.label_salida.config(text="FIN")
            return

        bloque = self.palabras[self.indice:self.indice + self.n]
        self.label_salida.config(text=" ".join(bloque))

        self.indice += self.n
        self.root.after(self.tiempo, self.mostrar_bloque)


if __name__ == "__main__":
    root = tk.Tk()
    app = LectorApp(root)
    root.mainloop()