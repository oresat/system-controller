# OreSat "System controller" Board

## Overview

The System Controller (SC) is part of the sputnik capstone project and is a robust module that is a vital piece of the avionics stack for the cubesat. It is tasked with performing the most critical job of all: monitoring the well-being of the stack and power cycling modules when [Single-Event Upsets](https://en.wikipedia.org/wiki/Single_event_upset) happen. At the heart of the module will be a radiation hardened microcontroller that communicates with the Low Gain Radio and Payload via UART. There are power switches with circuit breakers ("efuses") connected to the microcontroller that allow it to control the flow of power to all of the other systems/modules on the CubeSat.

## Main Topics
[Parts Selection](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md)  
[Bill of Materials](https://github.com/oresat/system-controller/blob/master/docs/BOM_SC.xls)  
[Eagle Schematic](https://github.com/oresat/low-gain-radio/blob/master/eagle/low-gain-radio.sch)    
[Eagle Layout](https://github.com/oresat/low-gain-radio/blob/master/eagle/low-gain-radio.brd)    
[Test Plan](https://github.com/oresat/low-gain-radio/blob/master/docs/Test_Plan_Sputnik_Capstone.md#sputnik-capstone-test-plan)   

## Contents

datasheets - datasheets for components used

docs - documentation

eagle - contains Schematic and PCB layout for the System Controller

firmware - contains firmware for the System Controller and tools for compiling/debugging

## Project team

Industry Sponsor: Andrew Greenberg (adg@ece.pdx.edu)

Faculty Advisor: Dr. Christof Teuscher (teuscher@pdx.edu)

* Capstone Team

    * William Harrington (wrh2@pdx.edu)

    * Shan Quinney (quinney@pdx.edu)

    * Jake Heath (jakeheath@gmail.com)

    * Mike Mathis (mdmathis@gmail.com)
