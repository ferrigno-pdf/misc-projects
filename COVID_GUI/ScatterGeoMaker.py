import csv
from collections import Counter, defaultdict, OrderedDict
import matplotlib.pyplot as plt
from plotly import offline
from plotly.graph_objs import Scatter, Bar, Line, Scattergeo, Layout

filename = 'COVID19_open_line_list.csv'
# special dictionary for counting values
counts = Counter()
# empty dictionary for coordinates
coord_dic = {}
# opens file
with open(filename) as f:
    # reads csv
    reader = csv.reader(f)
    # omits header
    header_row = next(reader)
    # loops through cvs's rows
    for row in reader:
        # counts the number of time a country appears on our file
        counts[row[3]] += 1
        try:
            # tries to get lattitude and longitude
            lat = float(row[7])
            lon = float(row[8])
        except:
            # if it's not possible to get coordinates ignores
            continue
        else:
            # creates a dictionary with country name as key and lat, long as values
            coord_dic[row[3]] = [lon,lat] 

full = {}
# orders dictionary
for k,v in sorted(coord_dic.items()):
    for k1, v1 in sorted(counts.items()):
        # if keys are the same, creates dictionary with country as key
        # and lat, long, and number of cases as values
        if k == k1:
            full[k] = [v,v1]

# removed empty value that appears on dictionary
full.pop('')

def make_scattergeo():
    """
    Function for creating a scattergeo; world map with cases' concentration
    """
    
    # dictionary for getting graph visuals in order.
    data = [{
        'type':'scattergeo',
        'lon':[f[0][0] for f in full.values()],
        'lat':[f[0][1] for f in full.values()],
        'text':[k for k in full.keys()],
        'marker':{
            'size':[f[-1]/5 for f in full.values()],
            'color':[f[-1] for f in full.values()],
            'colorscale':'Viridis',
            'reversescale':True,
            'colorbar':{'title': 'Contagios'},
        },
        }]
    # layout 
    layout1 = Layout(title='COVID-19 cases around the world between January and February 2020')
    # complete figure
    fig = {'data':data, 'layout':layout1}
    # plots and saves as filename
    offline.plot(fig, filename='infections.html')

# for testing
if __name__ == '__main__':
    make_scattergeo()

