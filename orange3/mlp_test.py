import pandas as pd
import numpy as np

from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score

df = pd.read_csv('/home/yj/kuuniv.bigdata2025/orange3/healthcate_dataset_3.csv')
print(df.shape)
print(df.info())
print(df.columns)

clf_mlp = MLPClassifier(max_iter=2000, random_state=0)
Y = df[df.columns[5]]
X = df.drop(columns=[df.columns[5]])
clf_mlp.fit(X, Y)
pred = clf_mlp.predict(X)
accuracy = accuracy_score(Y, pred)
print(accuracy)