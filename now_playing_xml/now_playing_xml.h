/////////////////////////////////////////////////////////////////////////////
//
// now_playing_xml.h : Declaration of the CNow_playing_xml
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __NOW_PLAYING_XML_H_
#define __NOW_PLAYING_XML_H_

#pragma once

#include "resource.h"
#include "wmpplug.h"

// {72A56DA7-9018-41F2-A884-6D9796A6B6EF}
DEFINE_GUID(CLSID_Now_playing_xml, 0x72a56da7, 0x9018, 0x41f2, 0xa8, 0x84, 0x6d, 0x97, 0x96, 0xa6, 0xb6, 0xef);

/////////////////////////////////////////////////////////////////////////////
// CNow_playing_xml
class ATL_NO_VTABLE CNow_playing_xml : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CNow_playing_xml, &CLSID_Now_playing_xml>,
    public IWMPEvents,
    public IWMPPluginUI
{
public:
    CNow_playing_xml();
    ~CNow_playing_xml();

DECLARE_REGISTRY_RESOURCEID(IDR_NOW_PLAYING_XML)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CNow_playing_xml)
    COM_INTERFACE_ENTRY(IWMPEvents)
    COM_INTERFACE_ENTRY(IWMPPluginUI)
END_COM_MAP()

    // CComCoClass methods
    HRESULT FinalConstruct();
    void    FinalRelease();

	// Now Playing XML Interface
	virtual HRESULT CreateXMLFile(const WCHAR *pwszFilePath);
	virtual void UpdateXMLFile(const WCHAR *pwszFilePath, long NewState);

    // IWMPPluginUI methods
    STDMETHODIMP SetCore(IWMPCore *pCore);
    STDMETHODIMP Create(HWND hwndParent, HWND *phwndWindow) { return E_NOTIMPL; }
    STDMETHODIMP Destroy() { return E_NOTIMPL; }
    STDMETHODIMP TranslateAccelerator(LPMSG lpmsg) { return E_NOTIMPL; }
    STDMETHODIMP DisplayPropertyPage(HWND hwndParent);
    STDMETHODIMP GetProperty(const WCHAR *pwszName, VARIANT *pvarProperty);
    STDMETHODIMP SetProperty(const WCHAR *pwszName, const VARIANT *pvarProperty);

    // IWMPEvents methods
    void STDMETHODCALLTYPE OpenStateChange( long NewState );
    void STDMETHODCALLTYPE PlayStateChange( long NewState );
    void STDMETHODCALLTYPE AudioLanguageChange( long LangID );
    void STDMETHODCALLTYPE StatusChange();
    void STDMETHODCALLTYPE ScriptCommand( BSTR scType, BSTR Param );
    void STDMETHODCALLTYPE NewStream();
    void STDMETHODCALLTYPE Disconnect( long Result );
    void STDMETHODCALLTYPE Buffering( VARIANT_BOOL Start );
    void STDMETHODCALLTYPE Error();
    void STDMETHODCALLTYPE Warning( long WarningType, long Param, BSTR Description );
    void STDMETHODCALLTYPE EndOfStream( long Result );
    void STDMETHODCALLTYPE PositionChange( double oldPosition, double newPosition);
    void STDMETHODCALLTYPE MarkerHit( long MarkerNum );
    void STDMETHODCALLTYPE DurationUnitChange( long NewDurationUnit );
    void STDMETHODCALLTYPE CdromMediaChange( long CdromNum );
    void STDMETHODCALLTYPE PlaylistChange( IDispatch * Playlist, WMPPlaylistChangeEventType change );
    void STDMETHODCALLTYPE CurrentPlaylistChange( WMPPlaylistChangeEventType change );
    void STDMETHODCALLTYPE CurrentPlaylistItemAvailable( BSTR bstrItemName );
    void STDMETHODCALLTYPE MediaChange( IDispatch * Item );
    void STDMETHODCALLTYPE CurrentMediaItemAvailable( BSTR bstrItemName );
    void STDMETHODCALLTYPE CurrentItemChange( IDispatch *pdispMedia);
    void STDMETHODCALLTYPE MediaCollectionChange();
    void STDMETHODCALLTYPE MediaCollectionAttributeStringAdded( BSTR bstrAttribName,  BSTR bstrAttribVal );
    void STDMETHODCALLTYPE MediaCollectionAttributeStringRemoved( BSTR bstrAttribName,  BSTR bstrAttribVal );
    void STDMETHODCALLTYPE MediaCollectionAttributeStringChanged( BSTR bstrAttribName, BSTR bstrOldAttribVal, BSTR bstrNewAttribVal);
    void STDMETHODCALLTYPE PlaylistCollectionChange();
    void STDMETHODCALLTYPE PlaylistCollectionPlaylistAdded( BSTR bstrPlaylistName);
    void STDMETHODCALLTYPE PlaylistCollectionPlaylistRemoved( BSTR bstrPlaylistName);
    void STDMETHODCALLTYPE PlaylistCollectionPlaylistSetAsDeleted( BSTR bstrPlaylistName, VARIANT_BOOL varfIsDeleted);
    void STDMETHODCALLTYPE ModeChange( BSTR ModeName, VARIANT_BOOL NewValue);
    void STDMETHODCALLTYPE MediaError( IDispatch * pMediaObject);
    void STDMETHODCALLTYPE OpenPlaylistSwitch( IDispatch *pItem );
    void STDMETHODCALLTYPE DomainChange( BSTR strDomain);
    void STDMETHODCALLTYPE SwitchedToPlayerApplication();
    void STDMETHODCALLTYPE SwitchedToControl();
    void STDMETHODCALLTYPE PlayerDockedStateChange();
    void STDMETHODCALLTYPE PlayerReconnect();
    void STDMETHODCALLTYPE Click( short nButton, short nShiftState, long fX, long fY );
    void STDMETHODCALLTYPE DoubleClick( short nButton, short nShiftState, long fX, long fY );
    void STDMETHODCALLTYPE KeyDown( short nKeyCode, short nShiftState );
    void STDMETHODCALLTYPE KeyPress( short nKeyAscii );
    void STDMETHODCALLTYPE KeyUp( short nKeyCode, short nShiftState );
    void STDMETHODCALLTYPE MouseDown( short nButton, short nShiftState, long fX, long fY );
    void STDMETHODCALLTYPE MouseMove( short nButton, short nShiftState, long fX, long fY );
    void STDMETHODCALLTYPE MouseUp( short nButton, short nShiftState, long fX, long fY );

    WCHAR        m_wszPluginText[MAX_PATH];

private:
    void         ReleaseCore();

    CComPtr<IWMPCore>           m_spCore;
    CComPtr<IConnectionPoint>   m_spConnectionPoint;
    DWORD                       m_dwAdviseCookie;
};

#endif //__NOW_PLAYING_XML_H_
