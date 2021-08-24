from tkinter import *
from finance_calculator import compound_interest
import tkinter.font as font

master = Tk()
master.title('Compound Interest Calculator')
master.geometry('400x400')
master.configure(bg='gray')

class Application:
    def __init__(self, master):
        myFrame = Frame(master)
        myFrame.pack()
        myFont = font.Font(family='Times New Roman', size=15)
        myLabel = Label(master, text='Compound Interest Calculator',bg='gray',fg='white',width=200,font=('Times New Roman',20)).pack(pady=15)
        
        principal_label = Label(master, text='Principal Amount',bg='gray',fg='white',width=200,font=('Times New Roman',20)).pack(pady=15)

        self.principal_entry = Entry(master,font="Helvetica 20 bold")
        self.principal_entry.pack(ipady=10)
        self.principal_entry.focus_set()

        rate_label = Label(master, text='Rate',bg='gray',fg='white',width=200,font=('Times New Roman',20)).pack(pady=15)

        self.rate_entry = Entry(master,font="Helvetica 20 bold")
        self.rate_entry.pack(ipady=10)
        self.rate_entry.focus_set()

        time_label = Label(master, text='Time',bg='gray',fg='white',width=200,font=('Times New Roman',20)).pack(pady=15)
        
        self.time_entry = Entry(master,font="Helvetica 20 bold")
        self.time_entry.pack(ipady=10)
        self.time_entry.focus_set()

        compounded_label = Label(master, text='Compounded',bg='gray',fg='white',width=200,font=('Times New Roman',20)).pack(pady=15)

        self.compounded_entry = Entry(master,font="Helvetica 20 bold")
        self.compounded_entry.pack(ipady=10)
        self.compounded_entry.focus_set()

        self.button1 = Button(
            master, text='Calculate Compound Interest', width=30,
            height=3, command=self.compound_interest_caller,
            highlightbackground='#556B2F',fg='black')
        self.button1['font'] = myFont
        self.button1.pack(pady=20)
        
        self.result_label = Label(master, text=f'Your Total Amount is: ',bg='gray',fg='white',width=200,font=('Times New Roman',20))
        self.result_label.pack(pady=15)
    



    def compound_interest_caller(self):
        principal = float(self.principal_entry.get())
        rate = float(self.rate_entry.get())
        time = float(self.time_entry.get())
        compounded = float(self.compounded_entry.get())
        result = compound_interest(principal, rate, time, compounded)
        self.result_label.configure(text=f'Your Total Amount is: {result} dollars')


    


e = Application(master)

master.mainloop()
