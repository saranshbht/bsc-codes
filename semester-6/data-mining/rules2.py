def rule1(dataset):
    return dataset[(dataset['Species'] == 'versicolor') | (dataset['Species'] == 'setosa') | (dataset['Species'] == 'virginica')]

def rule2(dataset):
    return dataset[(dataset['Sepal.Length'] > 0) & (dataset['Sepal.Width'] > 0) & (dataset['Petal.Length'] > 0) & (dataset['Petal.Width'] > 0)]

def rule3(dataset):
    return dataset[dataset['Petal.Length'] >= 2 * dataset['Petal.Width']]

def rule4(dataset):
    return dataset[dataset['Sepal.Length'] <= 30]

def rule5(dataset):
    return dataset[dataset['Sepal.Length'] > dataset['Petal.Length']]

