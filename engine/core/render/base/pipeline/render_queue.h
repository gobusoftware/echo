#pragma once

#include "irender_queue.h"
#include <engine/core/render/base/renderable.h>
#include <engine/core/scene/node.h>

namespace Echo
{
	class RenderQueue : public IRenderQueue
	{
		ECHO_CLASS(RenderQueue, IRenderQueue)

	public:
		RenderQueue() {}
		RenderQueue(RenderStage* stage);
		virtual ~RenderQueue();

		// render
		virtual void render();

		// add render able
		void addRenderable(RenderableID id) { m_renderables.emplace_back(id); }

		// sort
		void setSort(bool isSort) { m_isSort = isSort; }
		bool isSort() const { return m_isSort; }

	protected:
		bool							m_isSort;
		vector<RenderableID>::type		m_renderables;
	};
}
