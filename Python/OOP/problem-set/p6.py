from random import randint

class train:

    def __init__(slf,trainno):
        slf.trainno=trainno

    def book(self,fro,to):
        print(f"ticket is booked in train no: {self.trainno} from {fro} to {to}")

    def getstatus(self):
        print(f"train no: {self.trainno} is running on time")

    def getfare(self,fro,to,fare):
        if fare!=0:
            print(f"ticket fare in train no: {self.trainno} from {fro} to {to} is {fare}")
        else:
            print(f"ticket fare in train no: {self.trainno} from {fro} to {to} is {randint(150,500)}")

t=train(12532)
t.book("gorakhpur","lucknow")
t.getstatus()
t.getfare("gorakhpur","lucknow",0)
t.getfare("lucknow","gorakhpur",500)
