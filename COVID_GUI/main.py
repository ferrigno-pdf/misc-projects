from tkinter import * 
import ScatterGeoMaker as sg 
import api_graph as ag
import tkinter.font as font

# Creates window with information
master = Tk()
master.title('Select action')
master.geometry('500x400')
master.configure(bg='midnight blue')

class Gui:
    def __init__(self, master):
        # Frame
        myFrame = Frame(master)
        myFrame.pack()
        # Font
        myFont = font.Font(family='Sans', size=15)
        # Label
        myLabel = Label(master, text='What would you like to do?',bg='midnight blue',fg='white',width=200,font=('Serif',20)).pack(pady=15)
        # First Button
        # Button's action calls method which in turn calls our ScatterGeo function
        self.button1 = Button(
            master, text='Create ScatterGeo', width=30,
            height=3, command=self.sg_call,
            highlightbackground='dodger blue',fg='white')
        # button font
        self.button1['font'] = myFont
        self.button1.pack(pady=20)
        # Second label
        myLabel1 = Label(master, text='To get a country\'s graph, use lowercase only. \nIf the desired country\'s name contains whitespace, use hypens instead',bg='midnight blue',fg='white',width=200,font=('Museo Sans',15)).pack()
        # Entry which will be passed as argument for api_graph()
        self.entry = Entry(master,font="Lora 20 bold")
        self.entry.pack(ipady=10)
        self.entry.focus_set()
        # Second buttton which another method, which calls our api_graph() as well
        self.button2 = Button(
            master, width=30, height=3, text="Create Graph", 
            command=self.callback, highlightbackground='dodger blue', fg='white'
            )
        
        # Button font
        self.button2['font'] = myFont
        self.button2.pack(pady=30)



    def callback(self):
        """Calls function to get real time line graph from API"""
        return ag.api_line_graph(self.entry.get())

    def sg_call(self):
        """Calls our function to make ScatterGeo"""
        return sg.make_scattergeo()

e = Gui(master)

master.mainloop()





