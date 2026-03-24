import numpy as np

trainExamples = [
    (1, 1),
    (2, 3),
    (4, 3),
]

def phi(x):
    return np.array([1, x])

def initialWeightVector():
    return np.zeros(2)

def trainloss(w):
    return 1.0 / len(trainExamples) * sum((w.dot(phi(x)) - y) ** 2 for x, y in trainExamples)

def gradientTrainloss(w):
    return 2.0 / len(trainExamples) * sum((w.dot(phi(x)) - y) * phi(x) for x, y in trainExamples)

def gradientDescent(F, gradF, initialW):
    w = initialW
    eta = 0.1
    for t in range(500):
        value = F(w)
        grad = gradF(w)
        w = w - eta * grad
        print(f"epoch {t}: w = {w}, F(w) = {value}, gradF(w) = {grad}")
    
gradientDescent(trainloss, gradientTrainloss, initialWeightVector())