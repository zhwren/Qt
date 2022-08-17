/*************************************************************
**                         _ooOoo_                          **
**                        o8888888o                         **
**                        88" . "88                         **
**                        (| -_- |)                         **
**                         O\ = /O                          **
**                     ____/`---'\____                      **
**                   .   ' \\| |// `.                       **
**                    / \\||| : |||// \                     **
**                  / _||||| -:- |||||- \                   **
**                    | | \\\ - /// | |                     **
**                  | \_| ''\---/'' | |                     **
**                   \ .-\__ `-` ___/-. /                   **
**                ___`. .' /--.--\ `. . __                  **
**             ."" '< `.____<|>_/___.' >'"".                **
**            | | : `- \`.;` _ /`;.`/ - ` : | |             **
**              \ \ `-. \_ __\ /__ _/ .-` / /               **
**      ======`-.____`-.___\_____/___.-`____.-'======       **
**                         `=---='                          **
**                                                          **
**      .............................................       **
**             Buddha bless me, No bug forever              **
**                                                          **
**************************************************************
** Author       : generator                                 **
** Email        : zhuhw@ihep.ac.cn/zhwren0211@whu.edu.cn    **
** Last modified: TIME_CONTEXT                        **
** Filename     : demo_interface.sv
** Discription  :                                           **
*************************************************************/
`ifndef __DEMO_INTERFACE_SV__
`define __DEMO_INTERFACE_SV__

`include "demo_dec.sv"
import demo_dec::*;

interface demo_interface(input clk, input rst_n);
    INTERFACE_CONTEXT

    clocking drv_cb @(posedge clk);
	DRVCB_CONTEXT
    endclocking

    clocking mon_cb @(posedge clk);
	MONCB_CONTEXT
    endclocking
endinterface

`endif
