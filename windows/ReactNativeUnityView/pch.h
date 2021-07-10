#pragma once

#define NOMINMAX

#include <hstring.h>
#include <restrictederrorinfo.h>
#include <unknwn.h>
#include <windows.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.UI.Xaml.Controls.Primitives.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Data.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Windows.UI.Xaml.Markup.h>
#include <winrt/Windows.UI.Xaml.Navigation.h>
#include <winrt/Windows.UI.Xaml.h>

#include <winrt/Microsoft.ReactNative.h>

#include <winrt/Microsoft.UI.Xaml.Automation.Peers.h>
#include <winrt/Microsoft.UI.Xaml.Controls.Primitives.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>
#include <winrt/Microsoft.UI.Xaml.XamlTypeInfo.h>

#include <winrt/UnityPlayer.h>
using namespace winrt::Windows::Foundation;

struct HandleHolder
{
    inline HandleHolder(HANDLE handle) :
        m_Handle(handle)
    {
    }

    HandleHolder(const HandleHolder&) = delete;
    HandleHolder& operator=(const HandleHolder&) = delete;

    inline ~HandleHolder()
    {
        if (m_Handle != INVALID_HANDLE_VALUE)
            CloseHandle(m_Handle);
    }

    inline operator HANDLE() const
    {
        return m_Handle;
    }

private:
    HANDLE m_Handle;
};