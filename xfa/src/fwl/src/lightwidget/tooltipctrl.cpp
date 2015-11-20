// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "../../../foxitlib.h"
#include "../core/include/fwl_targetimp.h"
#include "../core/include/fwl_noteimp.h"
#include "../core/include/fwl_widgetimp.h"
#include "../core/include/fwl_panelimp.h"
#include "../core/include/fwl_formimp.h"
#include "../core/include/fwl_threadimp.h"
CFWL_ToolTip* CFWL_ToolTip::Create() {
  return new CFWL_ToolTip;
}
FWL_ERR CFWL_ToolTip::Initialize(const CFWL_WidgetProperties* pProperties) {
  _FWL_RETURN_VALUE_IF_FAIL(!m_pIface, FWL_ERR_Indefinite);
  if (pProperties) {
    *m_pProperties = *pProperties;
  }
  CFWL_WidgetImpProperties prop;
  prop.m_dwStyles = m_pProperties->m_dwStyles;
  prop.m_dwStyleExes = m_pProperties->m_dwStyleExes;
  prop.m_dwStates = m_pProperties->m_dwStates;
  prop.m_ctmOnParent = m_pProperties->m_ctmOnParent;
  prop.m_pDataProvider = &m_tooltipData;
  if (m_pProperties->m_pParent) {
    prop.m_pParent = m_pProperties->m_pParent->GetWidget();
  }
  if (m_pProperties->m_pOwner) {
    prop.m_pOwner = m_pProperties->m_pOwner->GetWidget();
  }
  prop.m_rtWidget = m_pProperties->m_rtWidget;
  m_pIface = IFWL_ToolTip::Create();
  FWL_ERR ret = ((IFWL_ToolTip*)m_pIface)->Initialize(prop, nullptr);
  if (ret == FWL_ERR_Succeeded) {
    CFWL_Widget::Initialize();
  }
  return ret;
}
FWL_ERR CFWL_ToolTip::GetCaption(CFX_WideString& wsCaption) {
  wsCaption = m_tooltipData.m_wsCaption;
  return FWL_ERR_Succeeded;
}
FWL_ERR CFWL_ToolTip::SetCaption(const CFX_WideStringC& wsCaption) {
  m_tooltipData.m_wsCaption = wsCaption;
  return FWL_ERR_Succeeded;
}
int32_t CFWL_ToolTip::GetInitialDelay() {
  return m_tooltipData.m_nInitDelayTime;
}
int32_t CFWL_ToolTip::SetInitialDelay(int32_t nDelayTime) {
  m_tooltipData.m_nInitDelayTime = nDelayTime;
  return FWL_ERR_Succeeded;
}
int32_t CFWL_ToolTip::GetAutoPopDelay() {
  return m_tooltipData.m_nAutoPopDelayTime;
}
int32_t CFWL_ToolTip::SetAutoPopDelay(int32_t nDelayTime) {
  m_tooltipData.m_nAutoPopDelayTime = nDelayTime;
  return FWL_ERR_Succeeded;
}
CFX_DIBitmap* CFWL_ToolTip::GetToolTipIcon() {
  return m_tooltipData.m_pBitmap;
}
FWL_ERR CFWL_ToolTip::SetToolTipIcon(CFX_DIBitmap* pBitmap) {
  m_tooltipData.m_pBitmap = pBitmap;
  return FWL_ERR_Succeeded;
}
CFX_SizeF CFWL_ToolTip::GetToolTipIconSize() {
  return m_tooltipData.m_fIconSize;
}
FWL_ERR CFWL_ToolTip::SetToolTipIconSize(CFX_SizeF fSize) {
  m_tooltipData.m_fIconSize = fSize;
  return FWL_ERR_Succeeded;
}
FWL_ERR CFWL_ToolTip::SetAnchor(const CFX_RectF& rtAnchor) {
  return ((IFWL_ToolTip*)m_pIface)->SetAnchor(rtAnchor);
}
FWL_ERR CFWL_ToolTip::Show() {
  return ((IFWL_ToolTip*)m_pIface)->Show();
}
FWL_ERR CFWL_ToolTip::Hide() {
  return ((IFWL_ToolTip*)m_pIface)->Hide();
}
CFWL_ToolTip::CFWL_ToolTip() {}
CFWL_ToolTip::~CFWL_ToolTip() {}
CFWL_ToolTip::CFWL_ToolTipDP::CFWL_ToolTipDP() : m_pBitmap(NULL) {
  m_wsCaption = L"";
  m_nInitDelayTime = 500;
  m_nAutoPopDelayTime = 50000;
  m_fIconSize.Set(0.0, 0.0);
  m_fAnchor.Set(0.0, 0.0, 0.0, 0.0);
}
FWL_ERR CFWL_ToolTip::CFWL_ToolTipDP::GetCaption(IFWL_Widget* pWidget,
                                                 CFX_WideString& wsCaption) {
  wsCaption = m_wsCaption;
  return FWL_ERR_Succeeded;
}
int32_t CFWL_ToolTip::CFWL_ToolTipDP::GetInitialDelay(IFWL_Widget* pWidget) {
  return m_nInitDelayTime;
}
int32_t CFWL_ToolTip::CFWL_ToolTipDP::GetAutoPopDelay(IFWL_Widget* pWidget) {
  return m_nAutoPopDelayTime;
}
CFX_DIBitmap* CFWL_ToolTip::CFWL_ToolTipDP::GetToolTipIcon(
    IFWL_Widget* pWidget) {
  return m_pBitmap;
}
CFX_SizeF CFWL_ToolTip::CFWL_ToolTipDP::GetToolTipIconSize(
    IFWL_Widget* pWidget) {
  return m_fIconSize;
}
CFX_RectF CFWL_ToolTip::CFWL_ToolTipDP::GetAnchor() {
  return m_fAnchor;
}