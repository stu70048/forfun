`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/09/20 13:04:30
// Design Name: 
// Module Name: test_sim
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module test_sim();
reg clk;
reg [1:0]key_in;
wire [1:0]led_out;       
test u_test(
              clk,
              key_in,
              led_out
        );      
initial begin 
    clk  = 1'b0;
    key_in = 2'b11;
    #30 key_in = 2'b00;
    #30 key_in = 2'b01;
    #30 key_in = 2'b10;
    #30 key_in = 2'b11;
end        
always #2 clk = ~clk;       
endmodule
