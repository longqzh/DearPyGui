#pragma once

#include "mvItemRegistry.h"

namespace Marvel {

	MV_REGISTER_WIDGET(mvTheme, MV_ITEM_DESC_DEFAULT | MV_ITEM_DESC_ROOT | MV_ITEM_DESC_CONTAINER, StorageValueTypes::None, 1);
	class mvTheme : public mvAppItem
	{

	public:

		static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

		MV_APPLY_WIDGET_REGISTRATION(mvAppItemType::mvTheme, add_theme)

		MV_CREATE_CONSTANT(mvThemeCat_Core, 0);
		MV_CREATE_CONSTANT(mvThemeCat_Plots, 1);
		MV_CREATE_CONSTANT(mvThemeCat_Nodes, 2);

		MV_START_COMMANDS
		MV_END_COMMANDS

		MV_START_CONSTANTS
			MV_ADD_CONSTANT(mvThemeCat_Core),
			MV_ADD_CONSTANT(mvThemeCat_Plots),
			MV_ADD_CONSTANT(mvThemeCat_Nodes),
		MV_END_CONSTANTS

	public:

		explicit mvTheme(mvUUID uuid);

		// overriding until we can remove these
		bool preDraw() override { return true; }
		void postDraw() override {}

		void draw(ImDrawList* drawlist, float x, float y) override;
		void customAction() override;
		void alternativeCustomAction() override;
		bool canChildBeAdded(mvAppItemType type) override;
		void handleSpecificKeywordArgs(PyObject* dict) override;

	};

}
