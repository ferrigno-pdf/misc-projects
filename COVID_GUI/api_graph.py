import requests
from datetime import datetime
import json
import matplotlib.pyplot as plt


def api_line_graph(country):
    """
    Creates a line graph from real time COVID data
    """
    # data needs to be entered in the format specified on the GUI
    # url changes depending on user input
    url = f'https://api.covid19api.com/dayone/country/{country}/status/confirmed/live'
    # needed dictionaries for call (specified in API instructions)
    payload = {}
    headers = {}
    # response
    response = requests.request("GET", url, headers=headers, data = payload)
    # response converted into json format
    data_json = json.loads(response.text)
    # empty list with number of cases and dates
    dates, cases = [], []
    for item in data_json:
        # tries to get data from country entered by user
        try:
            case = int(item['Cases'])
            # formatted date (from datetime library)
            date = datetime.strptime(item['Date'], "%Y-%m-%dT%H:%M:%SZ")
        # if not possible block ignores
        except:
            continue
        # appends to each list
        else:
            dates.append(date)
            cases.append(case)
    # another try except block to make graph
    try:
        # minimum and maximum values for making graph
        xmin, xmax = min(dates), max(dates)
        ymin, ymax = min(cases), max(cases)
        # style, creating figure, and plotting
        plt.style.use('seaborn')
        fig, ax = plt.subplots()
        ax.plot(dates, cases)
        # sets label and title
        ax.set_xlabel('Date')
        ax.set_ylabel('Number of cases')
        ax.set_title(f'Number of cases from beginning of COVID to right now in {country.title()}')
        # sets limits from min to max
        ax.set_xlim([xmin,xmax])
        ax.set_ylim([ymin,ymax])
        # formats dates
        fig.autofmt_xdate()
        # rotation for getting xvalues to fit
        plt.xticks(rotation=60)
        plt.show()
    except:
        # if graph cannot be made, the console will display appropriate message
        print('\nCountry is not valid')

# default value for testing
if __name__ == '__main__':
    api_line_graph('mexico')
