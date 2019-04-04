print "Hello world"
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.pyplot import figure
figure(num=None, figsize=(10, 6), dpi=180, facecolor='w', edgecolor='k')


data_AXP = pd.read_csv("../stock-data-dow-jones/AXP.csv")
data_AAPL = pd.read_csv("../stock-data-dow-jones/AAPL.csv")
print data_AAPL.head()


print data_AAPL.date

data_AAPL.date = pd.to_datetime(data_AAPL['date'], format='%Y-%m-%d')

print data_AAPL.date

dif=data_AAPL.open - data_AAPL.close
plt.plot(data_AAPL.date,data_AAPL.open)
plt.plot(data_AAPL.date,dif)
plt.plot(data_AAPL.date,data_AAPL.close)
plt.savefig('testplot_script2.png')
plt.show()
