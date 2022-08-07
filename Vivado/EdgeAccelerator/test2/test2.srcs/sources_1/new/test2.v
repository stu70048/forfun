`timescale 1ns / 1ps

module test2(
        input sys_clk,
        input [1:0]btn,
        output reg [1:0]led
    );


wire wire_led1 = btn[0] & btn[1];
wire wire_led2 = btn[0] | btn[1];
always @(posedge sys_clk)begin
    if(wire_led1)
        led[0] <= 1'b1;
    else
        led[0] <= 1'b0;
        
    if(wire_led2)
        led[1] <= 1'b1;
    else
        led[1] <= 1'b0; 
end
endmodule