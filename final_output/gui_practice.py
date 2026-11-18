# GUI of ESP32
import tkinter as tk
from tkinter import messagebox

#ESP32 connections
SIMULATE = False
PORT = "COM7"
BAUD = 9600

MODE_NAME = {1: "BLINK", 2: "ALT", 3: "RUN"}

root = tk.Tk()
root.title("GUI")
root.geometry("460x280")

# ---------- Status box ----------
box = tk.LabelFrame(root, text="Status:", font=("Arial", 12))
box.pack(padx=15, pady=15, fill="x")
status = tk.StringVar(value="---")
tk.Label(box, textvariable=status, font=("Arial", 36, "bold"),
         fg="darkviolet").pack(pady=15)

# ---------- Sending a mode ----------
ser = None
if SIMULATE:
    def send(n):
        print(f"GUI sent: {n}")
        status.set(MODE_NAME[n])
else:
    import serial
    try:
        ser = serial.Serial(PORT, BAUD, timeout=0)
    except serial.SerialException as e:
        messagebox.showerror("Serial error",
            f"Could not open {PORT}.\n\nClose the Serial Monitor and any "
            f"other GUI window, then check the port.\n\n{e}")
        raise SystemExit

    def send(n):
        ser.write(f"{n}\n".encode())
        print(f"GUI sent: {n}")

    buf = ""
    def poll():
        """Read STATUS:<name> lines coming from the ESP32."""
        global buf
        buf += ser.read(200).decode(errors="ignore")
        while "\n" in buf:
            line, buf = buf.split("\n", 1)
            line = line.strip()
            if line.startswith("STATUS:"):
                status.set(line[7:])
        root.after(50, poll)
    poll()

# ---------- Buttons ----------
row = tk.Frame(root)
row.pack(pady=10)
for text, n in (("BLINK", 1), ("ALT", 2), ("RUN", 3)):
    tk.Button(row, text=text, width=10, height=2,
              command=lambda n=n: send(n)).pack(side="left", padx=8)

def on_close():
    if ser:
        ser.close()
    root.destroy()

root.protocol("WM_DELETE_WINDOW", on_close)
root.mainloop()