/*****************************************************************************
**                                 _ooOoo_                                  **
**                                o8888888o                                 **
**                                88" . "88                                 **
**                                (| -_- |)                                 **
**                                 O\ = /O                                  **
**                             ____/`---'\____                              **
**                           .   ' \\| |// `.                               **
**                            / \\||| : |||// \                             **
**                          / _||||| -:- |||||- \                           **
**                            | | \\\ - /// | |                             **
**                          | \_| ''\---/'' | |                             **
**                           \ .-\__ `-` ___/-. /                           **
**                        ___`. .' /--.--\ `. . __                          **
**                     ."" '< `.____<|>_/___.' >'"".                        **
**                    | | : `- \`.;` _ /`;.`/ - ` : | |                     **
**                      \ \ `-. \_ __\ /__ _/ .-` / /                       **
**              ======`-.____`-.___\_____/___.-`____.-'======               **
**                                 `=---='                                  **
**                                                                          **
**              .............................................               **
**                     Buddha bless me, No bug forever                      **
**                                                                          **
******************************************************************************
** Author       : generator                                                 **
** Email        : zhuhw@ihep.ac.cn/zhwren0211@whu.edu.cn                    **
** Last modified: TIME_CONTEXT                                              **
** Filename     : demo_top.sv
** Phone Number :                                                           **
** Discription  :                                                           **
*****************************************************************************/
`ifndef __DEMO_TOP_SV__
`define __DEMO_TOP_SV__
TOP_INCLUDE_CONTEXT
`include "uvm_macros.svh"
import uvm_pkg::*;
`include "demo_tc.sv"

module demo_top;
    logic clk;
    logic rst_n;
    TOP_DECLARE_CONTEXT
    initial begin
        run_test();
    end
endmodule

`endif
