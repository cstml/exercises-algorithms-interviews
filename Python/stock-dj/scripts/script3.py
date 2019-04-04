print "Hello world"
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.pyplot import figure
figure(num=None, figsize=(13, 6), dpi=180, facecolor='w', edgecolor='k')


data_AXP = pd.read_csv("../stock-data-dow-jones/AXP.csv")
data_AAPL = pd.read_csv("../stock-data-dow-jones/AAPL.csv")

AXP=data_AXP
AAPL=data_AAPL

x=AXP.open
y=AAPL.close
e=(AXP.open+AXP.close)/2

plt.errorbar(x, y, e, linestyle='None', marker='^')
plt.show()
AXP["close"].plot()
AAPL["close"].plot()
plt.show()

