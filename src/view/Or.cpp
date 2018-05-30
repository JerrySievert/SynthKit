#include "../controller/Or.hpp"
#include "../../deps/rack-components/jacks.hpp"
#include "../../deps/rack-components/screws.hpp"

struct OrWidget : ModuleWidget {
  OrWidget(OrModule *module);
};

OrWidget::OrWidget(OrModule *module) : ModuleWidget(module) {
  box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  {
    SVGPanel *panel = new SVGPanel();
    panel->box.size = box.size;
    panel->setBackground(SVG::load(assetPlugin(plugin, "res/Or.svg")));
    addChild(panel);
  }

  addChild(Widget::create<JLHHexScrew>(Vec(1, 1)));
  addChild(Widget::create<JLHHexScrew>(Vec(31, 366)));

  addInput(Port::create<RCJackSmallLight>(Vec(10.23, 73), Port::INPUT, module,
                                          OrModule::TOP1_INPUT));
  addInput(Port::create<RCJackSmallLight>(Vec(10.23, 115), Port::INPUT, module,
                                          OrModule::TOP2_INPUT));

  addOutput(Port::create<RCJackSmallDark>(Vec(10.23, 158), Port::OUTPUT, module,
                                          OrModule::TOP_OUTPUT));

  addInput(Port::create<RCJackSmallLight>(Vec(10.23, 220), Port::INPUT, module,
                                          OrModule::BOTTOM1_INPUT));
  addInput(Port::create<RCJackSmallLight>(Vec(10.23, 262), Port::INPUT, module,
                                          OrModule::BOTTOM2_INPUT));

  addOutput(Port::create<RCJackSmallDark>(Vec(10.23, 305), Port::OUTPUT, module,
                                          OrModule::BOTTOM_OUTPUT));
}

Model *modelOr =
    Model::create<OrModule, OrWidget>("SynthKit", "Or", "Or", MIXER_TAG);
