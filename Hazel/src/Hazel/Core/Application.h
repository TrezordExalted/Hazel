#pragma once
#include "Hazel/Core/Core.h"

#include "Hazel/Core/Window.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"

#include "Hazel/Core/Timestep.h"

#include "Hazel/Core/LayerStack.h"
#include "Hazel/ImGui/ImGuiLayer.h"

namespace Hazel
{
	class Application
	{
	public:
		Application(const std::string& name = "Hazel App");
		virtual ~Application();

		void OnEvent(Event& e);
		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void Close();
		
		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;
		bool m_Running = true;
		bool m_Minimized = false;
		float m_LastFrameTime = 0.0;
	private:
		static Application* s_Instance;
	};


	// To be defined by client
	Application* CreateApplication();
}