# Galga Updater v1

<p align="center">
  <img src="https://github.com/leandrocotsa/galga-updater/blob/main/imgs/360.gif?raw=true" width="500" />
</p>

Galga Updater is a project I developed for my sister’s birthday and it’s a device that display updates about Galga (her dog). Since she has to leave for work and I work from home, I am the one that looks after her during the day. She keeps asking me how's Galga doing so I made this device so she gets the updates without having to ask.

##  What is it?

It’s a device that displays update messages about Galga throughout the day. If an anomalous situation is spotted by the carer, a message is sent to this device which will display it to the Galga owner. (Thank you dad for the wood work!)

<p align="center">
  <img src="https://github.com/leandrocotsa/galga-updater/blob/main/imgs/preview.jpg?raw=true" width="500" />
</p>

## Setup

Inside Galga Updater there is an ESP3266 board which has code to connect to a simple Node express app which receives HTTP requests with the update message and it stores it in-memory. The device requests a new message periodically and displays it on the LED displays with an horizontal scroll animation. 

<p align="center">
  <img src="https://github.com/leandrocotsa/galga-updater/blob/main/imgs/cables.jpg?raw=true" width="500" />
</p>

## Who is Galga?


<p align="center">
  <img src="https://github.com/leandrocotsa/galga-updater/blob/main/imgs/real-galga.jpg?raw=true" width="500" />
</p>

