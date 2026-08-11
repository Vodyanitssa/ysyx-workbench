module top (
    input  [ 7:0] sw,
    output [15:0] led
);
  assign led[0] = sw[0] ^ sw[1];
endmodule
