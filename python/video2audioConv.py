#!/usr/bin/env python3
from tkinter import Tk
from tkinter.filedialog import askopenfilename
import tkinter
import tkinter.font as tkFont
from tkinter import messagebox

import urllib.request
import urllib.error
import re
import sys
import time
import os
import pipes

from pydub import AudioSegment

window = tkinter.Tk()
window.geometry("1000x400")
window.resizable(1, 0)
window.title("Video To Audio Converter")

customFont = tkFont.Font(family="Helvetica", size=18)

#creeating the main function
def mainEvent():
    Tk().withdraw()
    filepath = askopenfilename()
    video_to_audio(filepath)
    time.sleep(1)
    wav_to_mp3(filepath)
    print("finished")
    message1 = "sucessfully converted " + filepath + " into audio!"
    messagebox.showinfo("Completed", message1)

def video_to_audio(fileName):
	try:
		file, file_extension = os.path.splitext(fileName)
		file = pipes.quote(file)
		if os.path.exists(file + ".wav"): print(file)
		video_to_wav = 'ffmpeg -i ' + file + file_extension + ' ' + file + '.wav'
		final_audio = 'lame '+ file + '.wav' + ' ' + file + '.mp3'
		os.system(video_to_wav)
		os.system(final_audio)
		print("sucessfully converted ", fileName, " into audio!")
	except OSError as err:
		print(err.reason)
		exit(1) 

def wav_to_mp3(fileName):
    try:
        file, file_extension = os.path.splitext(fileName)
        file = pipes.quote(file)
        dst = file + ".mp3"
        src = file + ".wav"
        sound = AudioSegment.from_mp3(src)
        sound.export(dst, format="wav")
        os.remove(file + '.wav')
    except FileNotFoundError as err:
        print("Unsupported File Selected")
tkinter.Label(window, font=customFont , text="\tWelcome\n\n \tYou Can Convert Any Video File To Mp3 Instantly\n \tSupported Video Files:\n \tMp4, MKV, FLV, AVI and many more.\n\n\n \t*Note: Select Only Video Files\n\n \tVersion 1.0\n \tDeveloped By Aditya Nadamuni", width=50).pack(side="left")
tkinter.Button(window, font=customFont, text="Choose Video File", width=40, height=40, command= mainEvent).pack(side="bottom")
window.mainloop()
