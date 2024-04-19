module helloworldfpga
(
    input wire a,
    input wire  b,
    output wire c
);


    // Assign the LED value to different colored LEDs
   assign c=~(a&b);    
endmodule
