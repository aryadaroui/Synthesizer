# SynthBoy

A simple digital, hardware synth for our EE 400D class. so

![logo](assets/logo.png)



## Proposal

You’re a budding musician and you want to start playing with synths like your dad used to when he was in his Depeche Mode cover band. Unfortunately, all the products on the market are really expensive and complicated. SynthBoy, on the other hand, is an inexpensive, simple, entry-level synthesizer that sounds great! Dogs are cool. Cats suck. 2

### For whom?

SynthBoy is for musicians that want to try out their first hardware synth without spending tons of cash.

### What is it?

A hardware synthesizer with keys and adjustment knobs enclosing a Raspberry Pi with a custom synthesizer engine.

### Why would you do this?

Music is something humans are intrinisically connected to. A lot of people consume it, and a lot of people want to create it. Keyboards are easy to use, but synths are complicated. This bridges the gap.

### How is it different?

There are a lot of musical keyboard options on the market. Most synthesizers are very expensive and are very complicated. There are also a lot of options that are too braindead, just MIDI sampling different insruments. This is a genuine synthesizer that is customizable, simple, small, and cheap.

## Skills needed

-   Git
-   C++
-   MATLAB
-   3D-Modeling & printing
-   Raspberry Pi
-   Soldering
-   Basic electronics lab skills



## I/O and diagram

-   Input
    -   Gen. (Generated signal) signal
        -   Freq. selection
            -   12 musical keys
            -   Octave + button
            -   Octave - button
        -   waveshape rotary switch 
    -   LFO (Low Frequency Oscillator)
        -   Frequency knob
        -   Waveshape rotary switch
        -   Mix knob
    -   Volume knob
    -   Hi-pass filter
        -   Freq. selection knob
        -   Mix knob
    -   Lo-pass filter
        -   Freq. selection knob
        -   Mix knob



```mermaid
graph LR
	freqLFO(LFO freq)-.->LFO[LFO]
	waveLFO(LFO shape) -.-> LFO
	mixLFO(LFO mix) -.-> LFO
	
	keys(24 keys) -.-> freqCarrier[CAR freq]
	octave(Octave) -.-> freqCarrier
	
	waveGen(CAR shape) -.-> Carrier[FM Carrier]
	
	hiFreq(Hi cut freq) -.-> hiCut[Hi cut]
	ADSR --> hiCut
	hiMix(Hi cut mix ) -.-> hiCut
	loFreq(Lo cut freq ) -.-> loCut[Lo cut]
	hiCut --> loCut
	loMix(Lo cut mix ) -.-> loCut
	
	LFO --> Carrier
	freqCarrier --> Carrier
	
	Attack -.-> ADSR
	Decay -.-> ADSR
	Carrier --> ADSR[ADSR Envelope]
	Sustain -.-> ADSR
	Release -.-> ADSR

	loCut --> DAC
    DAC --> extEQ

	subgraph input
	freqLFO
	waveLFO
	mixLFO
	keys
	octave
	waveGen
	hiFreq
	hiMix
	loFreq
	loMix
	Attack
	Decay
	Sustain
	Release
	end
	
	subgraph Raspberry Pi
	LFO
	Carrier
	DAC
	ADSR
	hiCut
	loCut
	freqCarrier
	end
	
	subgraph output
	Amp --> Speaker
	extEQ[External EQ] --> Amp
	end
```



```mermaid
gantt
dateFormat  MM-DD

section Startup
Form teams:			done,	01-23,	7d
Product design:		done,	01-30,	4d
Write proposal:		active,	01-30,	5d
Learn Git:			      ,	02-04,	7d
Review C++:		      	  ,	02-04,	7d

section Synthesis Engine
Realtime audio structure:	02-10,	7d
FM Carrier signal:			7d
LFO signal:					7d
Waveshaping:				7d
ADSR Envelope:				7d
Filters:					7d
Systems Merge:				7d
Review and Documentation:	7d
Final touches:				04-28, 05-06

section Raspberry Pi
Install and strip OS:		03-31,	7d
Assign I/O : 				10d
Review and Documentation:	7d
Final touches:				04-28, 05-06

section Hardware
Draft 3D model:				04-07,	5d
Review & print:				4d
Attach decal:				2d
Assembly:					7d
Documentation:				3d
Final touches:				04-28, 05-06

section Deliverables
Final report:				05-06,	05-15
Final demo:					05-06,	05-15
```







