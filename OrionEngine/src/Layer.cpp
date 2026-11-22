#include "oepch.h"
#include "Layer.h"
namespace OrionEngine {
	Layer::Layer(const std::string& debugName)
		: m_DebugName(debugName) { }
	Layer::~Layer(){}
}