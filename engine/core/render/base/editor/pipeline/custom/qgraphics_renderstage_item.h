#pragma once

#include "engine/core/editor/editor.h"

#ifdef ECHO_EDITOR_MODE

#include <QPainter>

namespace Pipeline
{
	class QGraphicsRenderStageItem : public QGraphicsPathItem
	{
	public:
		QGraphicsRenderStageItem(QGraphicsItem* parent = nullptr)
			: QGraphicsPathItem(parent)
		{}

		// is focused
		bool isFocused() const { return m_focused; }

		// hover event callback
		void setHoverEnterEventCb(std::function<void(QGraphicsItem*)> cb) { m_hoverEnterEventCb = cb;}
		void setHoverEnterLeaveCb(std::function<void(QGraphicsItem*)> cb) { m_hoverLeaveEventCb = cb; }

		// mouse event cb
		void setMousePressEventCb(std::function<void(QGraphicsItem*)> cb) { m_mousePressEventCb = cb; }

	protected:
		virtual void focusInEvent(QFocusEvent* event)
		{
			m_focused = true;
		}

		virtual void focusOutEvent(QFocusEvent* event)
		{
			m_focused = false;
		}

		virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override
		{
			QGraphicsPathItem::hoverEnterEvent(event);

			if (m_hoverEnterEventCb)
				m_hoverEnterEventCb(this);
		}

		virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override
		{
			QGraphicsPathItem::hoverLeaveEvent(event);

			if (m_hoverLeaveEventCb)
				m_hoverLeaveEventCb(this);
		}

		virtual void mousePressEvent(QGraphicsSceneMouseEvent* event)
		{
			if (m_mousePressEventCb)
				m_mousePressEventCb(this);
		}

	protected:
		// position changed etc...
		virtual QVariant itemChange(GraphicsItemChange change, const QVariant& value)
		{
			return QGraphicsPathItem::itemChange(change, value);
		}

	protected:
		bool								m_focused = false;
		std::function<void(QGraphicsItem*)> m_hoverEnterEventCb;
		std::function<void(QGraphicsItem*)> m_hoverLeaveEventCb;
		std::function<void(QGraphicsItem*)> m_mousePressEventCb;
	};
}

#endif
