def rule1(dataset):
    return (dataset['Age'] >= 0) & (dataset['Age'] <= 150)

def rule2(dataset):
    return dataset['Age'] > dataset['yearsmarried']

def rule3(dataset):
    return (dataset['status'] == 'married') | (dataset['status'] == 'single') | (dataset['status'] == 'widowed')

def rule4(dataset):
    a = dataset[dataset['Age'] < 18]['agegroup'] == 'child'
    b = dataset[(dataset['Age'] >= 18) & (dataset['Age'] <= 65)]['agegroup'] == 'adult'
    c = dataset[dataset['Age'] > 65]['agegroup'] == 'elderly'
    return a.append(b).append(c).sort_index(axis = 0)
