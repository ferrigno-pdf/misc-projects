# Project Overview

This project is dedicated to a thorough analysis of Austin's Housing Market. It aims to unravel the trends and patterns that characterize the historical and current state of the market by scrutinizing key indicators such as population growth, housing prices, and residence supply data.

The inspiration for this project stems from Will Parker's comprehensive Wall Street Journal article relating to the subject. The article can be found at: https://www.wsj.com/economy/housing/once-americas-hottest-housing-market-austin-is-running-in-reverse-94226027?mod=Searchresults_pos1&page=1

The Heatmap of Austin's residential permits cannot be viewed on GitHub directly. To view this Heatmap, please visit the following link: https://nbviewer.org/github/ferrigno-pdf/misc-projects/blob/main/Austin_Housing_Market_Analysis/Analyzing_ATX_Data.ipynb

This link provides a view of the notebook where the Heatmap can be interacted with.

# Objective

The primary objective of this notebook is to gain a nuanced understanding of the forces shaping Austin's Housing Market and provide evidence of a market cooldown. Through this analysis, we aim to provide a data-driven narrative that encapsulates the market's evolution, assesses its current status, and anticipates future developments.

# Data Sources

The data sources used for this analysis are the following (also cited in the notebook):

- **Austin Metro Area Population from 1950 to 2024:** https://www.macrotrends.net/global-metrics/cities/22926/austin/population#:~:text=The%20current%20metro%20area%20population,a%202.39%25%20increase%20from%202022.
  
- **Housing Price Index Values per State:** https://www.fhfa.gov/DataTools/Downloads/Documents/HPI/HPI_AT_state.csv

- **Historical Home Value Dataset:** https://www.zillow.com/research/data/ (home value forecasts dataset)

- **Issued Construction Permits for the City of Austin (by way of API):** https://data.austintexas.gov/Building-and-Development/Issued-Construction-Permits/3syk-w9eu/about_data

# Analytical Approach

The notebook follows a structured approach to analysis, which includes:

Data Cleaning and Preprocessing: Ensuring the quality and consistency of the datasets for accurate analysis.
Exploratory Data Analysis (EDA): Conducting initial examinations of trends and patterns in the datasets.
Time Series Analysis: Looking at how key metrics have changed over time and trending behaviors.
Comparative Analysis: Comparing Austin's market trends with state and national averages to contextualize our findings.
Visualization: Employing a range of visual tools to illustrate the data and enhance interpretability.

# Tools and Technologies

Python: The primary programming language used for data manipulation and analysis.
Jupyter Notebooks: An interactive computational environment where the analysis is performed and documented.
Pandas: A library used for data manipulation and analysis.
Numpy: A library used for mathematical operations.
Datetime: A build in Python library for creating datetime objects
Matplotlib: Library used for data visualization (line plots and bar graphs).
Folium: Library used for geographical heatmap visualization.

# Findings and Conclusions
The notebook concludes with key findings that reflect the market's state as it relates to the balance between supply and demand, pricing trends, and population growth. These findings highlight significant evidence of a cooling phase in what has been one of the hottest housing markets in recent years.

# How to Use This Notebook

Reproduction of Analysis: You can run the Jupyter Notebook cells sequentially to reproduce the analysis. Ensure all data dependencies are resolved by downloading necessary datasets if they are not bundled with the notebook.

Independent Exploration: Feel free to manipulate the provided datasets or integrate additional data for independent exploration and hypothesis testing.

Reporting Issues: If you encounter issues or have questions, please open an issue in the repository with a detailed description.

# License

This project is open-sourced under the MIT license. All contributions to this project will be subject to this open-source license.

Please read the license terms carefully before using or contributing to this project.

# Contact

For any further inquiries or doubts, please reach out to ferrigno.pdf@gmail.com
