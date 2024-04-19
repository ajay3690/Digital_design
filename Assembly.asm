.include "m328pdef.inc"

; Define patterns for 1, 0, and . for a common cathode 7-segment
.def pattern1D = r16
.def pattern0D = r17
.def patterndotD = r18
.def pattern1B = r19
.def pattern0B = r20
.def patterndotB = r21

; Initialization for segments on PORTD
ldi pattern1D, 0b00111100 ; '1' pattern for common cathode
ldi pattern0D, 0b00000000 ; '0' pattern for common cathode
ldi patterndotD, 0b11111111 ; '.' pattern for common cathode (only the dp segment on PORTB will be active)

; Initialization for segments on PORTB
ldi pattern1B, 0b11111111 ; '1' pattern for common cathode (none of the segments on PORTB are used for '1')
ldi pattern0B, 0b11111111 ; '0' pattern for common cathode (none of the segments on PORTB are used for '0')
ldi patterndotB, 0b11111101 ; '.' pattern for common cathode (only dp segment is active)

; Set PORTD and PORTB pins as output
ldi r22, 0xFF
out DDRD, r22
ldi r22, 0x03  ; Set the first two bits of PORTB as output
out DDRB, r22

; Display loop
loop:
    ; Display the sequence 1,1,0,1,1,.,1,0,1 with 1s delay between each digit/point
    rcall display1
    rcall display1
    rcall display0
    rcall display1
    rcall display1
    rcall displaydot
    rcall display1
    rcall display0
    rcall display1

    rjmp loop

display1:
    out PORTD, pattern1D
    out PORTB, pattern1B
    rcall delay_1000ms
    ret

display0:
    out PORTD, pattern0D
    out PORTB, pattern0B
    rcall delay_1000ms
    ret

displaydot:
    out PORTD, patterndotD
    out PORTB, patterndotB
    rcall delay_1000ms
    ret

; Approximate 1000ms (1 second) delay subroutine using nested loops
delay_1000ms:
    ldi r26, 10     ; 10 repetitions of ~100ms delay to approximate 1000ms
delay_rep_outer:
    ldi r23, 8     ; 8 repetitions of ~12.3ms delay to approximate 100ms
delay_rep_inner:
    ldi r24, 0xFF  ; Outer loop counter
outer_loop:
    ldi r25, 0xFF  ; Inner loop counter
inner_loop:
    dec r25
    brne inner_loop
    dec r24
    brne outer_loop
    dec r23
    brne delay_rep_inner
    dec r26
    brne delay_rep_outer
    ret
