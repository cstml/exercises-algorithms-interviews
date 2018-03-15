# import libraries
import numpy as np
import pandas as pd 
import matplotlib.pyplot as plt
import dateutil
from matplotlib.sankey import Sankey

#import CSV
names =['Date','Code','Task','Hours','Notes']
dataset = pd.read_csv("Vlad_timesheet_record.csv",names=names,header=0)

#parse CSV to make project information confidential 

#convert hours from string to float
length = dataset['Date'].count() - 1
dataset= dataset [:length]
dataset['Hours'] = pd.to_numeric(dataset['Hours'])


# Convert date from string to date times
dataset['Date'] = dataset['Date'].apply(dateutil.parser.parse)


#print (dataset.groupby('Code').size())
fig = dataset.groupby(['Date','Code'])['Hours'].count()
#print (fig)
#.boxplot()
#dataset.histplot(column='Hours',by='Code')
#print (fig.describe)
#plt.fig()
#plt.show()

fig, ax = plt.subplots(figsize=(15,7))
dataset.groupby(['Date','Code']).count()['Hours'].unstack().plot(ax=ax)
info = dataset.groupby('Date')['Hours'].sum()
plt.info(legend=True)
plt.show
