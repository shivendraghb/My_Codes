import speech_recognition as sr
import webbrowser
import pyttsx3

recognizer = sr.Recognizer()# recognizer class is used to recognize speech
engine=pyttsx3.init()# text to speech engine initialization

def speak(text):
    engine.say(text)
    engine.runAndWait()

if __name__ == "__main__":
    speak("hello, world")
