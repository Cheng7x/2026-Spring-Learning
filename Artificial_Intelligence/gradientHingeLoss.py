import numpy as np

trainExamples = [
    ((0, 2), 1),
    ((-2, 0), 1),
    ((1, -1), -1)
]

def phi(x):
    return np.array(x)

def initialWeightVector():
    return np.zeros(2)

def trainloss(w):
    return 1.0 / len(trainExamples) * sum((max(0, 1 - y * w.dot(phi(x))) for x, y in trainExamples))

def gradientTrainloss(w):
    return 1.0 / len(trainExamples) * sum(-phi(x) * y if 1 - y * w.dot(phi(x)) > 0 else 0 for x, y in trainExamples)

def gradientDescent(F, gradF, initialW):
    w = initialW
    eta = 0.1
    for t in range(10):
        value = F(w)
        grad = gradF(w)
        w = w - eta * grad
        print(f"epoch {t}: w = {w}, F(w) = {value}, gradF(w) = {grad}")
    
gradientDescent(trainloss, gradientTrainloss, initialWeightVector())