import numpy as np
import math

trueW = np.array([1, 2, 3, 4, 5])
def generate():
    x = np.random.randn(len(trueW))
    y = trueW.dot(x) + np.random.randn()
    # print(f"Generated example: x = {x}, y = {y}")
    return (x, y)

trainExamples = [generate() for _ in range(10000)]

def phi(x):
    return np.array(x)

def initialWeightVector():
    return np.zeros(len(trueW))

def trainloss(w):
    return 1.0 / len(trainExamples) * sum((w.dot(phi(x)) - y) ** 2 for x, y in trainExamples)

def gradientTrainloss(w):
    return 2.0 / len(trainExamples) * sum((w.dot(phi(x)) - y) * phi(x) for x, y in trainExamples)

def loss(w, i):
    x, y = trainExamples[i]
    return (w.dot(phi(x)) - y) ** 2

def gradientLoss(w, i):
    x, y = trainExamples[i]
    return 2.0 * (w.dot(phi(x)) - y) * phi(x)

def gradientDescent(F, gradF, initialW):
    w = initialW
    eta = 0.1
    for t in range(500):
        value = F(w)
        grad = gradF(w)
        w = w - eta * grad
        print(f"epoch {t}: w = {w}, F(w) = {value}, gradF(w) = {grad}")
    
def stochasticGradientDescent(F, gradF, n, initialW):
    w = initialW()
    numUpdates = 0
    for t in range(500):
        for i in range(n):
            value = F(w, i)
            gradient = gradF(w, i)
            numUpdates += 1
            eta = 1.0 / math.sqrt(numUpdates)
            w = w - eta * gradient
        print(f"epoch {t}: w = {w}, F(w) = {value}, gradF(w) = {gradient}") # type: ignore

# gradientDescent(trainloss, gradientTrainloss, initialWeightVector())
stochasticGradientDescent(loss, gradientLoss, len(trainExamples), initialWeightVector)