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
** Author       : ZhuHaiWen                                 **
** Email        : zhuhw@ihep.ac.cn/zhwren0211@whu.edu.cn    **
** Last modified: TIME_CONTEXT                       **
** Filename     : demo_monirot.sv
** Discription  :                                           **
*************************************************************/
`ifndef __DEMO_MONITOR_SV__
`define __DEMO_MONITOR_SV__

`include "demo_xaction.sv"

class demo_monitor extends uvm_monitor #(demo_xaction);
    `uvm_component_utils_begin(demo_monitor)
    `uvm_component_utils_end

    extern function new(string name="demo_monitor", uvm_component parent=null);
endclass

/*************************************************************
** Time        : TIME_CONTEXT                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
function demo_monitor::new(string name="demo_monitor", uvm_componet parent=null);
    super.new(name, parent);
endfunction

`endif
