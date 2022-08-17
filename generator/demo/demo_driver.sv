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
** Filename     : demo_driver.sv
** Phone Number :                                                           **
** Discription  :                                                           **
*****************************************************************************/
`ifndef __DEMO_DRIVER_SV__
`define __DEMO_DRIVER_SV__

`include "demo_dec.sv"
`include "demo_xaction.sv"
`include "demo_interface.sv"
import demo_dec::*;

class demo_driver extends uvm_driver #(demo_xaction);
    virtual demo_interface vif;

    `uvm_component_utils_begin(demo_driver)
    `uvm_component_utils_end

    extern function new(string name="demo_driver", uvm_component parent=null);
    extern function void connect_phase(uvm_phase phase);
    extern task main_phase(uvm_phase phase);
    extern task drive_one_pkt(demo_xaction tr);
endclass

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
function demo_driver::new(string name="demo_driver", uvm_component parent=null);
    super.new(name, parent);
endfunction

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
function void demo_driver::connect_phase(uvm_phase phase);
    super.connect_phase(phase);
    if (!uvm_confog_db#(virtual demo_interface)::get(this, "", "demo_interface", vif)) begin
	`uvm_fatal(get_name(), $sformatf("demo_interface is null"));
    end
endfunction

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
task demo_driver::main_phase(uvm_phase phase);
    while (1) begin
	@vif.drv_cb;
	seq_item_port.try_next_item(req);
	if (req == null) begin
	    req = new();
	    req.randomize() with {VLD_CONTEXT == '0;};
	    drive_one_pkt(req);
	end else begin
	    drive_one_pkt(req);
	    seq_item_port.item_done();
	end
    end
endtask

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
task demo_driver::drive_one_pkt(demo_xaction tr);
    DRIVER_CONTEXT
endtask

`endif
