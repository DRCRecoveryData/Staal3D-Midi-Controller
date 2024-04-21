## Summary
![Staal3D-Midi-Cont-04](https://github.com/DRCRecoveryData/Staal3D-Midi-Controller/assets/85211068/636d7e14-54a4-4693-9f1a-00585dcda38e)
![Staal3D-Midi-Cont-03](https://github.com/DRCRecoveryData/Staal3D-Midi-Controller/assets/85211068/decfe686-414a-4e0e-97d3-f13ef99d1903)
![Staal3D-Midi-Cont-02](https://github.com/DRCRecoveryData/Staal3D-Midi-Controller/assets/85211068/f5c45818-b455-427f-923f-7b7b4b62d3cc)
![Staal3D-Midi-Cont-01-nuked](https://github.com/DRCRecoveryData/Staal3D-Midi-Controller/assets/85211068/e5dca504-25eb-4940-bd7e-5f173e5ca024)
![6629e132206a7fcbfeeeec5411d0c656](https://github.com/DRCRecoveryData/Staal3D-Midi-Controller/assets/85211068/65c12e88-5dc5-4444-88fa-898ded79f11a)
![5d53c37840d57e67ebd7ef3d566de21b](https://github.com/DRCRecoveryData/Staal3D-Midi-Controller/assets/85211068/6479bb27-ca77-4a55-95f4-438fdbccf563)

This MIDI Controller is designed for use with various DAWs and music programs, styled after the MIDI Fighter unit for an enjoyable playing experience. It has been successfully tested with Ableton Live, Reason, Garage Band, and Traktor, proving to work seamlessly. Users have the flexibility to MIDI map it according to their preferences. The controller features 4 analog and 16 digital outputs.

## Hardware Requirements

To build this MIDI controller, you will need the following hardware components:

- On/off switch (size: 12.9mm x 19.4mm)
- 16 Sanwa 24mm Arcade buttons (or compatible clones)
- 4 knobs (size: 15mm x 17mm, KN-11/WS)
- 4 10k potentiometers
- 8 4-6mm M3 button head screws
- Arduino Mega (mounting screws or glue gun)
- Dupont wires for the Arduino
- Wires for the buttons and potentiometers

## Software Setup

To program the Arduino, use the MocoLufa boot loader, enabling reprogramming without the need to flash the boot loader again. The ON/OFF switch facilitates this functionality. Refer to the MocoLUFA instructions provided in the following link:

[https://github.com/kuwatay/mocolufa](https://github.com/kuwatay/mocolufa)

For instructions on how to DFU on Mac, watch this video:

[https://www.youtube.com/watch?v=pHOSCIRoJG8](https://www.youtube.com/watch?v=pHOSCIRoJG8)

The Arduino sketch for this MIDI controller is provided by Gustavo Silveira. Check out his YouTube channel, The Musico Nerd, for extensive information on making MIDI controllers with Arduino:

[https://www.youtube.com/channel/UCyqCwyBJ98fR-CPoyXUxY5w](https://www.youtube.com/channel/UCyqCwyBJ98fR-CPoyXUxY5w)

## Sketch File

You can download the sketch file from the following link:

[https://www.dropbox.com/s/kgv656eeefdujr4/Staal3D-Midi-Controller.zip?dl=0](https://www.dropbox.com/s/kgv656eeefdujr4/Staal3D-Midi-Controller.zip?dl=0)

Feel free to modify the sketch as needed. Take note of Digital Pin 13, which has been disabled in the sketch to prevent unwanted triggering.

## Printing Settings

If you're 3D printing the case for the controller, here are the recommended settings:

- **Printer brand:** Prusa
- **Printer model:** Prusa Mk2
- **Rafts:** No
- **Supports:** Yes
- **Resolution:** 0.2
- **Infill:** 14
- **Notes:** Only the case requires support, but it can be printed without if your printer excels at bridging. Printed in 3DE Premium Flame Orange MAX PLA.


