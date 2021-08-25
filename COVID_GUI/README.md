COVID-19 Data Analysis (Version 1.0.0)

This Data Analysis uses a csv (located in this directory) and extracts live data
from an API, the following URL shows the source: https://documenter.getpostman.com/view/10808728/SzS8rjbc

On the document called main, a GUI is created. Depending on the clicked button,
it creates a ScatterGeo with data extracted from the csv or
creates a line graph with data exctracted from the API call.
For the API call to work, the entry format is specified on the GUI.
The two functions used for making the graphs are contained in separate files.
For creating the ScatterGeo, all code is found on "ScatterGeoMaker.py" and 
for creating the API line graph, all code is found on "api_graph.py".

The dependencies needed for usage of the program are the following:

- Python (version 3 or higher)
- Matplotlib
- Plotly

If you do not have any of these dependecies installed, please install Python 3 first,
and then install the mentioned libraries according to your command line specifications.
If you don't know how to install or have any trouble, refer to the following URL:
https://packaging.python.org/tutorials/installing-packages/



 



