`timescale 1ns / 1ps

module test2(
        input sys_clk,
        input [1:0]key,
        output reg led_l1_l2
    );


wire flag = key[0] & key[1];
always @(posedge sys_clk)begin
    if(flag)
        led_l1_l2 <= 1'b1;
    else
        led_l1_l2 <= 1'b0;
end
endmodule