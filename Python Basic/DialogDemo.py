import tkinter.messagebox
import tkinter.simpledialog
import tkinter.colorchooser

tkinter.messagebox.showinfo("showinfo", "This is an info msg")

tkinter.messagebox.showwarning("showwarning", "This is a warning")

tkinter.messagebox.showerror("showerror", "This is an error")

isYes = tkinter.messagebox.askyesno("ashyesno", "Continue?")
print(isYes)

isOK = tkinter.messagebox.askokcancel("ashokcancle", "OK?")
print(isOK)

isYesNoCancel = tkinter.messagebox.askyesnocancel(
    "askyesnocancel", "Yes, No, Cancel?") 
print(isYesNoCancel)

name = tkinter.simpledialog.askstring(
    "askstring", "Enter your name")
print(name)

age = tkinter.simpledialog.askinteger(
    "askinteger", "Enter your age")
print(age)

weight = tkinter.simpledialog.askfloat(
    "askfloat", "Enter your weight")
print(weight)
