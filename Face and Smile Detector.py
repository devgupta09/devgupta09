from tkinter import * 

import cv2

import matplotlib.pyplot as plt

root= Tk()
root.geometry('300x200')
root.title('Detector')
    
def face_detector():

    detector=cv2.CascadeClassifier('./haarcascade_frontalface_default.xml')

    Cam=cv2.VideoCapture(0)

    while True:
        ret,frame=Cam.read()

        if ret == False:
            continue

        all_smiles= detector.detectMultiScale(frame,1.5,5)

        for face in all_smiles:
            x,y,w,h= face
            frame= cv2.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),2)

        cv2.imshow("FACE DETECTOR", frame)

        key_pressed= cv2.waitKey(1) & 0xff
        if key_pressed == ord('q'):
            break

    Cam.release()
    cv2.destroyAllWindows()
    
def smile_detector():
    detector=cv2.CascadeClassifier('./haarcascade_smile.xml')

    Cam=cv2.VideoCapture(0)

    while True:
        ret,frame=Cam.read()

        if ret == False:
            continue

        all_smiles= detector.detectMultiScale(frame,1.5,70)
        smile=sorted(all_smiles,key= lambda s:s[-1]*s[-2])

        for face in all_smiles:
            x,y,w,h= smile[0]
            frame= cv2.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),2)

        cv2.imshow("SMILE DETECTOR", frame)

        key_pressed= cv2.waitKey(1) & 0xff
        if key_pressed == ord('q'):
            break

    Cam.release()
    cv2.destroyAllWindows()
    
def mask_detector():
    detector=cv2.CascadeClassifier('./haarcascade_smile.xml')

    Cam=cv2.VideoCapture(0)

    while True:
        ret,frame=Cam.read()

        if ret == False:
            continue

        all_smiles= detector.detectMultiScale(frame,1.5,70)
        smile=sorted(all_smiles,key= lambda s:s[-1]*s[-2])

        for face in all_smiles:
            x,y,w,h= smile[0]
            frame= cv2.rectangle(frame,(x,y),(x+w,y+h),(0,0,255),2)

        cv2.imshow("MASK DETECTOR", frame)

        key_pressed= cv2.waitKey(1) & 0xff
        if key_pressed == ord('q'):
            break

    Cam.release()
    cv2.destroyAllWindows()
    
    
smile=Button(root, text="MASK DETECTOR", command= mask_detector)
smile.place(x=100,y=20)

mask=Button(root, text="FACE DETECTOR"  , command= face_detector)
mask.place(x=0,y=100)

face=Button(root, text="SMILE DETECTOR"  , command= smile_detector)
face.place(x=200,y=100)

root.bind('<Return>',lambda event:callback())
root.mainloop()
