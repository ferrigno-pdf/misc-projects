from tkinter import *
from finance_calculator import compound_interest
import tkinter.font as font

# specifications for GUI window
master = Tk()
master.title('Compound Interest Calculator')
master.geometry('500x800')
master.configure(bg='gray')

class Application:
    def __init__(self, master):
        # attributes for GUI
        # setting up a new frame, title, and font specifications
        myFrame = Frame(master)
        myFrame.pack()
        myFont = font.Font(family='Times New Roman', size=15)
        # setting up title 
        myLabel = Label(master, text='Compound Interest Calculator',bg='gray',fg='white',width=200,font=('Times New Roman',20)).pack(pady=15)
        
        # Principal Amount label and entry 
        principal_label = Label(master, text='Principal Amount',bg='gray',fg='white',width=200,font=('Times New Roman',20)).pack(pady=15)

        self.principal_entry = Entry(master,font="Helvetica 20 bold")
        self.principal_entry.pack(ipady=10)
        self.principal_entry.focus_set()

        # Rate Amount label and entry 
        rate_label = Label(master, text='Rate (1-100)',bg='gray',fg='white',width=200,font=('Times New Roman',20)).pack(pady=15)

        self.rate_entry = Entry(master,font="Helvetica 20 bold")
        self.rate_entry.pack(ipady=10)
        self.rate_entry.focus_set()

        # Time Amount label and entry 
        time_label = Label(master, text='Time',bg='gray',fg='white',width=200,font=('Times New Roman',20)).pack(pady=15)
        
        self.time_entry = Entry(master,font="Helvetica 20 bold")
        self.time_entry.pack(ipady=10)
        self.time_entry.focus_set()

        # Compounded label and entry 
        compounded_label = Label(master, text='Compounded (1 for yearly, 2 for semiannually, etc.)',bg='gray',fg='white',width=200,font=('Times New Roman',20)).pack(pady=15)

        self.compounded_entry = Entry(master,font="Helvetica 20 bold")
        self.compounded_entry.pack(ipady=10)
        self.compounded_entry.focus_set()

        # Button which calls compound interest method (bellow)
        self.button1 = Button(
            master, text='Calculate Compound Interest', width=30,
            height=3, command=self.compound_interest_caller,
            highlightbackground='#556B2F',fg='black')
        self.button1['font'] = myFont
        self.button1.pack(pady=20)
        # Label to display the total amount
        self.result_label = Label(master, text=f'Your Total Amount is: ',bg='gray',fg='white',width=200,font=('Times New Roman',20))
        self.result_label.pack(pady=15)
    



    def compound_interest_caller(self):
        """
        Gets all the entries given by user and passes them as arguments
        for our compound interest function.
        """
        principal = float(self.principal_entry.get())
        rate = float(self.rate_entry.get())
        time = float(self.time_entry.get())
        compounded = float(self.compounded_entry.get())
        result = compound_interest(principal, rate, time, compounded)
        self.result_label.configure(text=f'Your Total Amount is: {result} dollars')


    


e = Application(master)

master.mainloop()
