/* ===== 23e144fc0 telegram.handlers.screenshot_han:16 ===== */
/* ghidra_name=FUN_23e144fc0 entry=23e144fc0 size=8150 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e144fc0(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  bool bVar3;
  undefined8 uVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  code *pcVar12;
  code *pcVar13;
  longlong *plVar14;
  longlong *plVar15;
  code *pcVar16;
  longlong *plVar17;
  undefined1 auVar18 [8];
  longlong *plVar19;
  code *pcVar20;
  code *pcVar21;
  code *pcVar22;
  longlong *plVar23;
  undefined4 uVar24;
  undefined1 auStack_c8 [16];
  code *pcStack_b8;
  undefined1 auStack_a8 [8];
  code *pcStack_a0;
  code *pcStack_98;
  code *pcStack_88;
  code *pcStack_80;
  code *pcStack_78;
  
  plVar9 = _DAT_23eeaaf58;
  pcStack_98 = (code *)0x0;
  auStack_a8 = (undefined1  [8])0x0;
  pcStack_a0 = (code *)0x0;
  if (_DAT_23eeaaf58 == (longlong *)0x0) {
LAB_23e145022:
    _DAT_23eeaaf58 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaaf48,DAT_23eeaaf50);
  }
  else {
    lVar11 = *_DAT_23eeaaf58;
    if (1 < lVar11) {
      *_DAT_23eeaaf58 = lVar11 + -1;
      goto LAB_23e145022;
    }
    if (_DAT_23eeaaf58[2] != 0) {
      *_DAT_23eeaaf58 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e145022;
    }
  }
  plVar23 = _DAT_23eeaaf58;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeaaf58 + 9;
  lVar1 = *(longlong *)(lVar11 + 8);
  _DAT_23eeaaf58[0xf] = lVar1;
  *(longlong **)(lVar11 + 8) = plVar9;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar23[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar23[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  lVar1 = DAT_23eea87c8;
  *plVar23 = *plVar23 + 1;
  *(undefined4 *)(plVar23 + 8) = 0;
  lVar11 = *(longlong *)(lVar1 + 0x20);
  if (*(char *)(lVar11 + 10) != '\0') {
    iVar7 = *(int *)(lVar11 + 0xc);
    if (*(int *)(lVar11 + 0xc) == 0) {
      *(int *)(lVar11 + 0xc) = _DAT_23ec14c50;
      iVar7 = _DAT_23ec14c50;
      _DAT_23ec14c50 = _DAT_23ec14c50 + 1;
    }
    if (_DAT_23ec14c54 != iVar7) {
      _DAT_23ec14c54 = iVar7;
      _DAT_23eeaaf40 = FUN_23e8cbd60(lVar11,DAT_23eea87e0,*(undefined8 *)(DAT_23eea87e0 + 0x18));
    }
    if (-1 < _DAT_23eeaaf40) {
      lVar1 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
      if (*(longlong *)(lVar1 + 8 + _DAT_23eeaaf40 * 0x10) != 0) goto LAB_23e145112;
      _DAT_23eeaaf40 = FUN_23e8cbd60(lVar11,DAT_23eea87e0,*(undefined8 *)(DAT_23eea87e0 + 0x18));
      if (-1 < _DAT_23eeaaf40) {
        lVar11 = *(longlong *)(lVar1 + 8 + _DAT_23eeaaf40 * 0x10);
        goto LAB_23e145fd0;
      }
    }
LAB_23e145731:
    plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eea87e0);
    if ((plVar9 != (longlong *)0x0) && (*plVar9 != 0)) goto LAB_23e145112;
    FUN_23e915740(param_1,auStack_a8,DAT_23eea87e0);
    if (pcStack_98 == (code *)0x0) goto LAB_23e146610;
    if (plVar23 == *(longlong **)(pcStack_98 + 0x18)) goto LAB_23e145a88;
    pcVar13 = (code *)0x0;
    pcVar21 = (code *)0x0;
    plVar9 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    uVar24 = 0x12;
    goto LAB_23e145e20;
  }
  plVar9 = (longlong *)FUN_23a37a020(lVar1,DAT_23eea87e0);
  if (plVar9 == (longlong *)0x0) goto LAB_23e145731;
  lVar11 = *plVar9;
LAB_23e145fd0:
  if (lVar11 == 0) goto LAB_23e145731;
LAB_23e145112:
  *(undefined4 *)(plVar23 + 5) = 0x12;
  plVar8 = (longlong *)FUN_23e91a870(param_1);
  if (plVar8 == (longlong *)0x0) {
    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_a0 = *(code **)(param_1 + 0x68);
    pcStack_98 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_98 != (code *)0x0) {
      if (*(longlong **)(pcStack_98 + 0x18) == plVar23) {
LAB_23e145a88:
        pcVar13 = (code *)0x0;
        pcVar21 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        pcVar20 = pcStack_98;
        goto LAB_23e145aa0;
      }
      pcVar13 = (code *)0x0;
      pcVar21 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      uVar24 = 0x12;
      goto LAB_23e145e20;
    }
LAB_23e146610:
    pcVar13 = (code *)0x0;
    pcVar21 = (code *)0x0;
    plVar9 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    uVar24 = 0x12;
    goto LAB_23e146290;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eea87e8);
  lVar11 = _DAT_23eea87f0;
  if (plVar9 == (longlong *)0x0) {
    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_a0 = *(code **)(param_1 + 0x68);
    pcStack_98 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_98 == (code *)0x0) {
LAB_23e146280:
      pcVar13 = (code *)0x0;
      pcVar21 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      uVar24 = 0x13;
      goto LAB_23e146290;
    }
    plVar10 = *(longlong **)(pcStack_98 + 0x18);
joined_r0x00023e145fa3:
    plVar9 = (longlong *)0x0;
    pcVar21 = (code *)0x0;
    pcVar13 = (code *)0x0;
    pcVar20 = pcStack_98;
    if (plVar10 == plVar23) goto LAB_23e145aa0;
    plVar9 = (longlong *)0x0;
    pcVar21 = (code *)0x0;
    pcVar13 = (code *)0x0;
    uVar24 = 0x13;
  }
  else {
    *(undefined4 *)(plVar23 + 5) = 0x13;
    plVar10 = (longlong *)FUN_23e9186b0(param_1,plVar9,lVar11 + 0x18);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar10 == (longlong *)0x0) {
      auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_a0 = *(code **)(param_1 + 0x68);
      pcStack_98 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcStack_98 == (code *)0x0) goto LAB_23e146280;
      plVar10 = *(longlong **)(pcStack_98 + 0x18);
      goto joined_r0x00023e145fa3;
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    lVar11 = FUN_23e8ffdf0();
    if (lVar11 == 0) {
      FUN_23e915740(param_1,auStack_a8,DAT_23eea8800);
      if (pcStack_98 == (code *)0x0) {
LAB_23e146790:
        pcVar13 = (code *)0x0;
        pcVar21 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        uVar24 = 0x16;
LAB_23e146290:
        pcVar20 = DAT_23ed6a4f8;
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          pcVar12 = pcStack_98;
        }
        else {
          pcVar12 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar12;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          pcVar12 = (code *)0x0;
        }
        pcVar16 = _PyRuntime_exref;
        *(longlong **)(pcVar20 + 0x18) = plVar23;
        *(longlong *)(pcVar20 + 0x10) = 0;
        *plVar23 = *plVar23 + 1;
        lVar11 = *(longlong *)(pcVar16 + 0x1f8);
        *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
        lVar11 = *(longlong *)(lVar11 + 0x10);
        *(undefined4 *)(pcVar20 + 0x24) = uVar24;
        lVar11 = *(longlong *)(lVar11 + 0x2e8);
        lVar1 = *(longlong *)(pcVar20 + -8);
        puVar2 = *(undefined8 **)(lVar11 + 8);
        *puVar2 = pcVar20 + -0x10;
        *(longlong *)(pcVar20 + -0x10) = lVar11;
        *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
        *(code **)(lVar11 + 8) = pcVar20 + -0x10;
        if ((pcVar12 != (code *)0x0) &&
           (*(longlong *)pcVar12 = *(longlong *)pcVar12 + -1, *(longlong *)pcVar12 == 0)) {
          (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
        }
        goto LAB_23e145aa0;
      }
      if (plVar23 != *(longlong **)(pcStack_98 + 0x18)) {
        pcVar13 = (code *)0x0;
        pcVar21 = (code *)0x0;
        uVar24 = 0x16;
        plVar9 = (longlong *)0x0;
        goto LAB_23e145e20;
      }
LAB_23e14601c:
      pcVar13 = (code *)0x0;
      pcVar21 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      pcVar20 = pcStack_98;
      goto LAB_23e145aa0;
    }
    *(undefined4 *)(plVar23 + 5) = 0x16;
    pcVar12 = (code *)FUN_23e91bfe0(param_1,lVar11);
    if (pcVar12 == (code *)0x0) {
      pcVar21 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar13 = *(code **)(param_1 + 0x60);
      pcVar20 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e145ff9:
      pcStack_98 = pcVar21;
      auStack_a8 = (undefined1  [8])pcVar13;
      pcStack_a0 = pcVar20;
      if (pcVar21 == (code *)0x0) goto LAB_23e146790;
      plVar9 = *(longlong **)(pcVar21 + 0x18);
joined_r0x00023e146016:
      if (plVar23 == plVar9) goto LAB_23e14601c;
      pcVar13 = (code *)0x0;
      pcVar21 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      uVar24 = 0x16;
    }
    else {
      plVar10 = (longlong *)FUN_23e8d9880(pcVar12,DAT_23ed6cd90);
      if (plVar10 == (longlong *)0x0) {
LAB_23e145ee0:
        pcVar21 = *(code **)(param_1 + 0x70);
        pcVar13 = *(code **)(param_1 + 0x60);
        pcVar20 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_98 = (code *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        auStack_a8 = (undefined1  [8])0x0;
        pcStack_a0 = (code *)0x0;
        *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
        if (*(longlong *)pcVar12 != 0) goto LAB_23e145ff9;
        (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
        pcStack_98 = pcVar21;
        auStack_a8 = (undefined1  [8])pcVar13;
        pcStack_a0 = pcVar20;
        if (pcVar21 == (code *)0x0) goto LAB_23e146790;
        plVar9 = *(longlong **)(pcVar21 + 0x18);
        goto joined_r0x00023e146016;
      }
      *(undefined4 *)(plVar23 + 5) = 0x16;
      plVar9 = (longlong *)FUN_23e91a870(param_1,plVar10);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar9 == (longlong *)0x0) goto LAB_23e145ee0;
      pcVar13 = (code *)FUN_23e8d9880(pcVar12,DAT_23ed6cd98);
      uVar4 = _DAT_23eea8808;
      if (pcVar13 == (code *)0x0) {
        pcVar20 = *(code **)(param_1 + 0x70);
        auVar18 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar16 = *(code **)(param_1 + 0x68);
        pcVar21 = (code *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = (longlong *)0x0;
        iVar7 = 0x16;
        *(undefined8 *)(param_1 + 0x70) = 0;
LAB_23e14638d:
        pcStack_98 = (code *)0x0;
        _auStack_a8 = (undefined1  [16])0x0;
        *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
        if (*(longlong *)pcVar12 == 0) {
          (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
        }
        lVar11 = *plVar9;
        *plVar9 = lVar11 + -1;
        if (lVar11 + -1 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
        if ((pcVar13 != (code *)0x0) &&
           (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0)) {
          (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
        }
        plVar9 = plVar10;
        auStack_a8 = auVar18;
        pcStack_a0 = pcVar16;
        if (pcVar20 != (code *)0x0) {
          pcVar13 = (code *)0x0;
          if (*(longlong **)(pcVar20 + 0x18) == plVar23) goto LAB_23e145aa0;
          pcStack_98 = pcVar20;
          if (iVar7 == 0) {
            uVar24 = (undefined4)plVar23[5];
          }
          else {
            uVar24 = 0x16;
          }
          goto LAB_23e145e20;
        }
        pcStack_98 = (code *)0x0;
        if (iVar7 == 0) {
          uVar24 = (undefined4)plVar23[5];
          pcVar13 = (code *)0x0;
        }
        else {
          pcVar13 = (code *)0x0;
          uVar24 = 0x16;
        }
        goto LAB_23e146290;
      }
      *plVar9 = *plVar9 + 1;
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar9,uVar4);
      plVar10 = plVar9;
      if (plVar14 == (longlong *)0x0) {
LAB_23e1457e0:
        auStack_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plVar14 = *(longlong **)(param_1 + 0x70);
        pcStack_98 = (code *)0x0;
        plVar15 = *(longlong **)(param_1 + 0x138);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        auStack_a8 = (undefined1  [8])0x0;
        pcStack_a0 = (code *)0x0;
        if (plVar15 != (longlong *)0x0) {
          *plVar15 = *plVar15 + 1;
        }
        pcVar21 = DAT_23ed6a4f8;
        pcStack_b8 = (code *)plVar14;
        if (plVar14 == (longlong *)0x0) {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar20 = *(code **)DAT_23ed6a4f8;
            *(longlong *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar20;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          *(longlong *)(pcVar21 + 0x10) = 0;
          *(longlong **)(pcVar21 + 0x18) = plVar23;
          *plVar23 = *plVar23 + 1;
          *(longlong *)(pcVar21 + 0x20) = 0x17ffffffff;
          lVar11 = *(longlong *)
                    (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar1 = *(longlong *)(pcVar21 + -8);
          puVar2 = *(undefined8 **)(lVar11 + 8);
          *puVar2 = pcVar21 + -0x10;
          *(longlong *)(pcVar21 + -0x10) = lVar11;
          *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
          *(code **)(lVar11 + 8) = pcVar21 + -0x10;
          if ((pcStack_b8 != (code *)0x0) &&
             (*(longlong *)pcStack_b8 = *(longlong *)pcStack_b8 + -1, *(longlong *)pcStack_b8 == 0))
          {
            (**(code **)(*(longlong *)((longlong)pcStack_b8 + 8) + 0x30))(pcStack_b8);
          }
        }
        else {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar20 = *(code **)DAT_23ed6a4f8;
            *(longlong *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar20;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          *(longlong **)(pcVar21 + 0x18) = plVar23;
          *plVar23 = *plVar23 + 1;
          *(longlong *)(pcVar21 + 0x20) = 0x17ffffffff;
          lVar11 = *(longlong *)
                    (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar1 = *(longlong *)(pcVar21 + -8);
          puVar2 = *(undefined8 **)(lVar11 + 8);
          *puVar2 = pcVar21 + -0x10;
          *(longlong *)(pcVar21 + -0x10) = lVar11;
          *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
          *(code **)(lVar11 + 8) = pcVar21 + -0x10;
          *(longlong **)(pcVar21 + 0x10) = plVar14;
          *plVar14 = *plVar14 + 1;
          if ((pcStack_b8 != (code *)0x0) &&
             (*(longlong *)pcStack_b8 = *(longlong *)pcStack_b8 + -1, *(longlong *)pcStack_b8 == 0))
          {
            (**(code **)(*(longlong *)((longlong)pcStack_b8 + 8) + 0x30))();
          }
        }
        pcVar20 = _Py_NoneStruct_exref;
        pcStack_b8 = pcVar21;
        if (((code *)auStack_c8._0_8_ != _Py_NoneStruct_exref) &&
           ((code *)auStack_c8._0_8_ != (code *)0x0)) {
          FUN_23e91b1b0(param_1,auStack_c8,auStack_c8 + 8);
        }
        plVar14 = *(longlong **)(auStack_c8._8_8_ + 0x28);
        if (pcStack_b8 == pcVar20) {
          pcVar21 = (code *)0x0;
        }
        else {
          pcVar21 = pcStack_b8;
          if (pcStack_b8 != (code *)0x0) {
            *(longlong *)pcStack_b8 = *(longlong *)pcStack_b8 + 1;
          }
        }
        *(code **)(auStack_c8._8_8_ + 0x28) = pcVar21;
        if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
          (**(code **)(plVar14[1] + 0x30))();
        }
        plVar14 = *(longlong **)(param_1 + 0x138);
        *(undefined8 *)(param_1 + 0x138) = auStack_c8._8_8_;
        if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
          (**(code **)(plVar14[1] + 0x30))();
        }
        *(longlong *)auStack_c8._0_8_ = *(longlong *)auStack_c8._0_8_ + -1;
        if (*(longlong *)auStack_c8._0_8_ == 0) {
          (**(code **)(*(longlong *)(auStack_c8._0_8_ + 8) + 0x30))();
        }
        if ((pcStack_b8 != (code *)0x0) &&
           (*(longlong *)pcStack_b8 = *(longlong *)pcStack_b8 + -1, *(longlong *)pcStack_b8 == 0)) {
          (**(code **)(*(longlong *)(pcStack_b8 + 8) + 0x30))();
        }
        pcStack_b8 = (code *)0x0;
        auStack_c8 = (undefined1  [16])0x0;
        iVar7 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                              *(undefined8 *)PyExc_BaseException_exref);
        pcVar21 = *(code **)(param_1 + 0x138);
        if (iVar7 == 0) {
          pcStack_a0 = pcVar21;
          if ((pcVar21 == pcVar20) || (pcVar21 == (code *)0x0)) {
            pcVar16 = (code *)0x0;
            pcVar20 = *(code **)PyExc_RuntimeError_exref;
            pcVar21 = (code *)PyUnicode_FromString("No active exception to reraise");
            bVar3 = true;
            pcVar22 = *(code **)(param_1 + 0x138);
            *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
            goto LAB_23e146699;
          }
          pcVar20 = *(code **)(pcVar21 + 8);
          pcVar16 = *(code **)(pcVar21 + 0x28);
          *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
          *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
          if (pcVar16 == (code *)0x0) {
            *(longlong **)(param_1 + 0x138) = plVar15;
            bVar3 = true;
            pcVar22 = pcVar21;
            iVar5 = 0;
          }
          else {
            *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
            if (*(longlong **)(pcVar16 + 0x18) == plVar23) {
              *(undefined4 *)(plVar23 + 5) = *(undefined4 *)(pcVar16 + 0x24);
            }
            bVar3 = true;
LAB_23e1464ab:
            *(longlong **)(param_1 + 0x138) = plVar15;
            pcVar22 = pcVar21;
            iVar5 = 0;
          }
LAB_23e1464cd:
          iVar7 = iVar5;
          pcStack_98 = (code *)0x0;
          _auStack_a8 = (undefined1  [16])0x0;
          *(longlong *)pcVar22 = *(longlong *)pcVar22 + -1;
          if (*(longlong *)pcVar22 == 0) {
            (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))();
          }
        }
        else {
          pcStack_88 = *(code **)(pcVar21 + 8);
          pcStack_78 = *(code **)(pcVar21 + 0x28);
          *(undefined4 *)(plVar23 + 5) = 0x16;
          if (pcStack_78 == (code *)0x0) {
            pcStack_78 = pcVar20;
          }
          pcStack_80 = pcVar21;
          plVar14 = (longlong *)FUN_23e956150(param_1,pcVar13,&pcStack_88);
          if (plVar14 == (longlong *)0x0) {
            pcVar16 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            bVar3 = false;
            pcVar22 = *(code **)(param_1 + 0x138);
            pcVar20 = *(code **)(param_1 + 0x60);
            pcVar21 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            iVar7 = FUN_23a35f020(plVar14);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (iVar7 == -1) {
              pcVar20 = *(code **)(param_1 + 0x60);
              pcVar21 = *(code **)(param_1 + 0x68);
              bVar3 = false;
              pcVar16 = *(code **)(param_1 + 0x70);
              pcVar22 = *(code **)(param_1 + 0x138);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
            }
            else {
              if (iVar7 != 0) {
                plVar14 = *(longlong **)(param_1 + 0x138);
                *(longlong **)(param_1 + 0x138) = plVar15;
                if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                  (**(code **)(plVar14[1] + 0x30))();
                }
                pcVar21 = (code *)0x0;
                goto LAB_23e1452db;
              }
              pcVar21 = *(code **)(param_1 + 0x138);
              pcStack_a0 = pcVar21;
              bVar3 = false;
              if ((pcVar21 != pcVar20) && (pcVar21 != (code *)0x0)) {
                pcVar20 = *(code **)(pcVar21 + 8);
                pcVar16 = *(code **)(pcVar21 + 0x28);
                *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
                *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                if (pcVar16 != (code *)0x0) {
                  *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
                  if (*(longlong **)(pcVar16 + 0x18) == plVar23) {
                    *(undefined4 *)(plVar23 + 5) = *(undefined4 *)(pcVar16 + 0x24);
                  }
                  goto LAB_23e1464ab;
                }
                *(longlong **)(param_1 + 0x138) = plVar15;
                pcVar22 = pcVar21;
                iVar5 = 0;
                goto LAB_23e1464cd;
              }
              pcVar16 = (code *)0x0;
              pcVar20 = *(code **)PyExc_RuntimeError_exref;
              pcVar21 = (code *)PyUnicode_FromString("No active exception to reraise");
              pcVar22 = *(code **)(param_1 + 0x138);
              *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
            }
          }
LAB_23e146699:
          *(longlong **)(param_1 + 0x138) = plVar15;
          iVar7 = 0x16;
          iVar5 = 0x16;
          if (pcVar22 != (code *)0x0) goto LAB_23e1464cd;
        }
        pcStack_98 = (code *)0x0;
        _auStack_a8 = (undefined1  [16])0x0;
        pcStack_88 = pcVar20;
        pcStack_80 = pcVar21;
        pcStack_78 = pcVar16;
        if (bVar3) {
          *(undefined4 *)(plVar23 + 5) = 0x16;
          plVar14 = (longlong *)FUN_23e957a30(param_1,pcVar13,_DAT_23eea8810);
          if (plVar14 == (longlong *)0x0) {
            pcStack_98 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            iVar7 = 0x16;
            auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_a0 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            FUN_23a35d6b0(&pcStack_88);
            pcVar21 = (code *)0x0;
            pcVar20 = pcStack_98;
            auVar18 = auStack_a8;
            pcVar16 = pcStack_a0;
            goto LAB_23e14638d;
          }
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
        }
        pcVar21 = (code *)0x0;
        pcVar20 = pcStack_78;
        auVar18 = (undefined1  [8])pcStack_88;
        pcVar16 = pcStack_80;
        goto LAB_23e14638d;
      }
      plVar15 = (longlong *)FUN_23e8bd600(param_1,plVar14);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar15 == (longlong *)0x0) goto LAB_23e1457e0;
      pcVar16 = (code *)FUN_23e8c6340(plVar15,1);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      *(undefined4 *)(plVar23 + 5) = 0x16;
      plVar17 = (longlong *)FUN_23e957a30(param_1,pcVar13,_DAT_23eea8810);
      plVar14 = plVar23;
      plVar15 = plVar8;
      if (plVar17 == (longlong *)0x0) {
LAB_23e146808:
        auVar18 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar20 = *(code **)(param_1 + 0x70);
        iVar7 = 0x16;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar23 = plVar14;
        plVar8 = plVar15;
        pcVar21 = pcVar16;
        pcVar16 = *(code **)(param_1 + 0x68);
        goto LAB_23e14638d;
      }
      *plVar17 = *plVar17 + -1;
      pcVar21 = pcVar16;
      if (*plVar17 == 0) {
        (**(code **)(plVar17[1] + 0x30))(plVar17);
      }
LAB_23e1452db:
      *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
      if (*(longlong *)pcVar12 == 0) {
        (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
      }
      lVar11 = *plVar9;
      *plVar9 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))();
      }
      *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
      if (*(longlong *)pcVar13 == 0) {
        (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
      }
      uVar4 = DAT_23ed6ccf8;
      if (pcVar21 != (code *)0x0) {
        plVar14 = (longlong *)FUN_23e8bf9b0(pcVar21,DAT_23ed6ccf8);
        if (plVar14 == (longlong *)0x0) {
          auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_a0 = *(code **)(param_1 + 0x68);
          pcStack_98 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (pcStack_98 != (code *)0x0) {
            if (plVar23 == *(longlong **)(pcStack_98 + 0x18)) {
LAB_23e146d40:
              pcVar13 = (code *)0x0;
              pcVar20 = pcStack_98;
              goto LAB_23e145aa0;
            }
            uVar24 = 0x19;
            pcVar13 = (code *)0x0;
            goto LAB_23e145e20;
          }
        }
        else {
          plVar15 = (longlong *)FUN_23e97e310(param_1,uVar4,plVar14);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar15 == (longlong *)0x0) {
            auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_a0 = *(code **)(param_1 + 0x68);
            pcStack_98 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (pcStack_98 != (code *)0x0) goto LAB_23e146772;
          }
          else {
            plVar17 = (longlong *)FUN_23ebf7180(plVar15);
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            pcVar13 = (code *)0x0;
            pcVar16 = pcVar21;
            if (plVar17 != (longlong *)0x0) {
              do {
                pcVar12 = (code *)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                if (pcVar12 == (code *)0x0) {
                  cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
                  if (cVar6 == '\0') {
                    pcVar20 = *(code **)(param_1 + 0x70);
                    auVar18 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcVar16 = *(code **)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pcStack_98 = (code *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    _auStack_a8 = (undefined1  [16])0x0;
                    if (pcVar13 == (code *)0x0) {
                      uVar24 = 0x19;
                      pcVar13 = pcVar12;
                      goto LAB_23e145d4b;
                    }
                    uVar24 = 0x19;
                    goto LAB_23e145d30;
                  }
                  if ((pcVar13 != (code *)0x0) &&
                     (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0))
                  {
                    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
                  }
                  lVar11 = *plVar17;
                  *plVar17 = lVar11 + -1;
                  if (lVar11 + -1 == 0) {
                    (**(code **)(plVar17[1] + 0x30))();
                  }
                  plVar10 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eea87e8);
                  lVar11 = _DAT_23eea8838;
                  if (plVar10 == (longlong *)0x0) {
                    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_a0 = *(code **)(param_1 + 0x68);
                    pcStack_98 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (pcStack_98 != (code *)0x0) {
                      pcVar20 = pcStack_98;
                      if (*(longlong **)(pcStack_98 + 0x18) == plVar23) goto LAB_23e145aa0;
LAB_23e146f96:
                      uVar24 = 0x1c;
                      goto LAB_23e145e20;
                    }
                  }
                  else {
                    *(undefined4 *)(plVar23 + 5) = 0x1c;
                    plVar14 = (longlong *)FUN_23e9186b0(param_1,plVar10,lVar11 + 0x18);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))();
                    }
                    if (plVar14 != (longlong *)0x0) {
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      *(undefined4 *)(plVar23 + 5) = 0x1d;
                      plVar10 = (longlong *)FUN_23e915840(param_1,plVar8,_DAT_23eea8840);
                      if (plVar10 == (longlong *)0x0) {
                        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_a0 = *(code **)(param_1 + 0x68);
                        pcStack_98 = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        if (pcStack_98 == (code *)0x0) {
                          uVar24 = 0x1d;
                          pcStack_98 = (code *)0x0;
                          goto LAB_23e146290;
                        }
                        pcVar20 = pcStack_98;
                        if (plVar23 == *(longlong **)(pcStack_98 + 0x18)) goto LAB_23e145aa0;
                        uVar24 = 0x1d;
                        goto LAB_23e145e20;
                      }
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      *(undefined4 *)(plVar23 + 5) = 0x1e;
                      lVar11 = FUN_23e91bfe0(param_1,plVar8,_DAT_23eea8850);
                      if (lVar11 != 0) {
                        lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                        plVar23 = *(longlong **)(lVar1 + 0x28);
                        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                             *(undefined8 *)(lVar1 + 0x30);
                        plVar10 = (longlong *)plVar23[2];
                        *(undefined4 *)(plVar23 + 8) = 0xffffffff;
                        if (plVar10 != (longlong *)0x0) {
                          plVar23[2] = 0;
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))();
                          }
                        }
                        *plVar23 = *plVar23 + -1;
                        if (*plVar23 == 0) {
                          (**(code **)(plVar23[1] + 0x30))(plVar23);
                        }
                        plVar23[0xf] = 0;
                        *plVar8 = *plVar8 + -1;
                        if (*plVar8 == 0) {
                          (**(code **)(plVar8[1] + 0x30))(plVar8);
                        }
                        lVar1 = *plVar9;
                        *plVar9 = lVar1 + -1;
                        if (lVar1 + -1 == 0) {
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                        *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
                        if (*(longlong *)pcVar21 == 0) {
                          (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
                        }
                        if (pcVar13 == (code *)0x0) {
                          return lVar11;
                        }
                        *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                        if (*(longlong *)pcVar13 != 0) {
                          return lVar11;
                        }
                        (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
                        return lVar11;
                      }
                      auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcStack_a0 = *(code **)(param_1 + 0x68);
                      pcStack_98 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      if (pcStack_98 == (code *)0x0) {
                        uVar24 = 0x1e;
                        pcStack_98 = (code *)0x0;
                        goto LAB_23e146290;
                      }
                      pcVar20 = pcStack_98;
                      if (*(longlong **)(pcStack_98 + 0x18) == plVar23) goto LAB_23e145aa0;
                      uVar24 = 0x1e;
                      goto LAB_23e145e20;
                    }
                    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_a0 = *(code **)(param_1 + 0x68);
                    pcStack_98 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (pcStack_98 != (code *)0x0) {
                      pcVar20 = pcStack_98;
                      if (plVar23 != *(longlong **)(pcStack_98 + 0x18)) goto LAB_23e146f96;
                      goto LAB_23e145aa0;
                    }
                  }
                  uVar24 = 0x1c;
                  goto LAB_23e146290;
                }
                if (pcVar13 == (code *)0x0) {
                  *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
                }
                else {
                  *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                  if (*(longlong *)pcVar13 == 0) {
                    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
                    lVar11 = *(longlong *)pcVar12;
                  }
                  else {
                    lVar11 = *(longlong *)pcVar12;
                  }
                  *(longlong *)pcVar12 = lVar11 + 1;
                  *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                  if (*(longlong *)pcVar13 == 0) {
                    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
                  }
                }
                plVar15 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eea87e8);
                pcVar13 = _DAT_23eea8828;
                if (plVar15 == (longlong *)0x0) {
LAB_23e1466f0:
                  pcVar20 = *(code **)(param_1 + 0x70);
                  auVar18 = *(undefined1 (*) [8])(param_1 + 0x60);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar24 = 0x1a;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pcVar13 = pcVar12;
                  pcVar16 = *(code **)(param_1 + 0x68);
                  goto LAB_23e145d30;
                }
                lVar11 = *(longlong *)(param_1 + 0x10);
                plVar14 = *(longlong **)(lVar11 + 0xe20);
                if (plVar14 == (longlong *)0x0) {
                  plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar1 = plVar14[3];
                  *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
                  *(longlong *)(lVar11 + 0xe20) = lVar1;
                  *plVar14 = 1;
                }
                pcVar20 = _PyRuntime_exref;
                plVar14[4] = 0;
                lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar20 + 0x1f8) + 0x10) + 0x2e8)
                ;
                lVar1 = plVar14[-1];
                puVar2 = *(undefined8 **)(lVar11 + 8);
                *puVar2 = plVar14 + -2;
                plVar14[-2] = lVar11;
                plVar14[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
                *(longlong **)(lVar11 + 8) = plVar14 + -2;
                *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
                plVar14[3] = (longlong)pcVar13;
                pcVar20 = DAT_23ed6cd28;
                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                  plVar19 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  if (plVar19 != (longlong *)0x0) {
                    *plVar19 = *plVar19 + 1;
                    DAT_23ed6a4c0 = plVar19;
                    goto LAB_23e1454df;
                  }
LAB_23e1467f0:
                  PyErr_PrintEx(0);
                  Py_Exit(1);
                  goto LAB_23e146808;
                }
LAB_23e1454df:
                pcStack_80 = pcVar20;
                pcStack_88 = pcVar12;
                lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_88);
                if (lVar11 == 0) {
                  _auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  pcStack_98 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
LAB_23e146b96:
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
LAB_23e146ba6:
                  uVar24 = 0x1a;
                  pcVar20 = pcStack_98;
                  pcVar13 = pcVar12;
                  auVar18 = auStack_a8;
                  pcVar16 = pcStack_a0;
                  goto LAB_23e145d30;
                }
                plVar14[4] = lVar11;
                pcVar16 = PyUnicode_Join_exref;
                pcVar13 = (code *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                plVar19 = _DAT_23eea8830;
                if (pcVar13 == (code *)0x0) {
                  auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_a0 = *(code **)(param_1 + 0x68);
                  pcStack_98 = *(code **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *plVar15 = *plVar15 + -1;
                  pcVar20 = pcStack_98;
                  auVar18 = auStack_a8;
                  pcVar16 = pcStack_a0;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                    pcVar20 = pcStack_98;
                    auVar18 = auStack_a8;
                    pcVar16 = pcStack_a0;
                  }
                  uVar24 = 0x1a;
                  pcVar13 = pcVar12;
                  goto LAB_23e145d30;
                }
                lVar11 = *(longlong *)(param_1 + 0x10);
                plVar14 = *(longlong **)(lVar11 + 0xe20);
                if (plVar14 == (longlong *)0x0) {
                  plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar1 = plVar14[3];
                  *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
                  *(longlong *)(lVar11 + 0xe20) = lVar1;
                  *plVar14 = 1;
                }
                pcVar20 = _PyRuntime_exref;
                plVar14[4] = 0;
                lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar20 + 0x1f8) + 0x10) + 0x2e8)
                ;
                lVar1 = plVar14[-1];
                puVar2 = *(undefined8 **)(lVar11 + 8);
                *puVar2 = plVar14 + -2;
                plVar14[-2] = lVar11;
                plVar14[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
                *(longlong **)(lVar11 + 8) = plVar14 + -2;
                *plVar19 = *plVar19 + 1;
                plVar14[3] = (longlong)plVar19;
                pcVar20 = DAT_23ed6cd28;
                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                  plVar19 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  if (plVar19 == (longlong *)0x0) goto LAB_23e1467f0;
                  *plVar19 = *plVar19 + 1;
                  DAT_23ed6a4c0 = plVar19;
                }
                pcStack_80 = pcVar20;
                pcStack_88 = pcVar12;
                lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_88);
                if (lVar11 == 0) {
                  _auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  pcStack_98 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                  if (*(longlong *)pcVar13 == 0) {
                    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
                  }
                  goto LAB_23e146b96;
                }
                plVar14[4] = lVar11;
                pcVar16 = (code *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                if (pcVar16 == (code *)0x0) {
                  _auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  pcStack_98 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                  if (*(longlong *)pcVar13 == 0) {
                    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
                  }
                  goto LAB_23e146ba6;
                }
                *(undefined4 *)(plVar23 + 5) = 0x1a;
                pcStack_88 = pcVar13;
                pcStack_80 = pcVar16;
                plVar14 = (longlong *)FUN_23e9186b0(param_1,plVar15,&pcStack_88);
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                if (*(longlong *)pcVar13 == 0) {
                  (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
                }
                *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
                if (*(longlong *)pcVar16 == 0) {
                  (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
                }
                if (plVar14 == (longlong *)0x0) goto LAB_23e1466f0;
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                lVar11 = *(longlong *)(param_1 + 0x10);
                if ((((*(int *)(*(longlong *)(lVar11 + 0x28) + 0x160) != 0) ||
                     (*(int *)(lVar11 + 0x78) != 0)) && (iVar7 = Py_MakePendingCalls(), iVar7 < 0))
                   && (auVar18 = *(undefined1 (*) [8])(param_1 + 0x60),
                      auVar18 != (undefined1  [8])0x0)) goto LAB_23e145cf0;
                if (*(int *)(lVar11 + 0x68) == 0) {
                  plVar14 = *(longlong **)(param_1 + 0x90);
                }
                else {
                  PyEval_SaveThread();
                  PyEval_AcquireThread(param_1);
                  plVar14 = *(longlong **)(param_1 + 0x90);
                }
                pcVar13 = pcVar12;
              } while (plVar14 == (longlong *)0x0);
              plVar10 = *(longlong **)(param_1 + 0x60);
              plVar15 = *(longlong **)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x90) = 0;
              plVar19 = *(longlong **)(param_1 + 0x70);
              *(longlong **)(param_1 + 0x60) = plVar14;
              *plVar14 = *plVar14 + 1;
              *(undefined8 *)(param_1 + 0x68) = 0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                (**(code **)(plVar10[1] + 0x30))();
              }
              if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                (**(code **)(plVar19[1] + 0x30))(plVar19);
              }
              auVar18 = *(undefined1 (*) [8])(param_1 + 0x60);
LAB_23e145cf0:
              pcVar20 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar24 = 0x19;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar13 = pcVar12;
              pcVar16 = *(code **)(param_1 + 0x68);
LAB_23e145d30:
              pcStack_98 = (code *)0x0;
              _auStack_a8 = (undefined1  [16])0x0;
              *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
              if (*(longlong *)pcVar13 == 0) {
                (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
              }
LAB_23e145d4b:
              lVar11 = *plVar17;
              *plVar17 = lVar11 + -1;
              if (lVar11 + -1 == 0) {
                (**(code **)(plVar17[1] + 0x30))();
              }
              auStack_a8 = auVar18;
              pcStack_a0 = pcVar16;
              if (pcVar20 == (code *)0x0) {
                pcStack_98 = (code *)0x0;
                goto LAB_23e146290;
              }
              plVar10 = *(longlong **)(pcVar20 + 0x18);
              goto joined_r0x00023e146783;
            }
            auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_a0 = *(code **)(param_1 + 0x68);
            pcStack_98 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (pcStack_98 != (code *)0x0) {
              if (plVar23 == *(longlong **)(pcStack_98 + 0x18)) goto LAB_23e146d40;
              pcVar13 = (code *)0x0;
              uVar24 = 0x19;
              goto LAB_23e145e20;
            }
          }
        }
        pcVar13 = (code *)0x0;
        uVar24 = 0x19;
        goto LAB_23e146290;
      }
      pcStack_a0 = (code *)PyUnicode_FromFormat
                                     ("cannot access local variable \'%U\' where it is not associated with a value"
                                      ,_DAT_23eea8818);
      auStack_a8 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
      *(longlong *)auStack_a8 = *(longlong *)auStack_a8 + 1;
      pcStack_98 = (code *)0x0;
      if (auStack_a8 != (undefined1  [8])_Py_NoneStruct_exref) {
        FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8);
      }
      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
      if (pcStack_98 == (code *)0x0) {
        pcVar13 = (code *)0x0;
        pcVar21 = (code *)0x0;
        uVar24 = 0x19;
        goto LAB_23e146290;
      }
LAB_23e146772:
      pcVar13 = (code *)0x0;
      uVar24 = 0x19;
      plVar10 = *(longlong **)(pcStack_98 + 0x18);
      pcVar20 = pcStack_98;
joined_r0x00023e146783:
      pcStack_98 = pcVar20;
      if (plVar23 == plVar10) goto LAB_23e145aa0;
    }
  }
LAB_23e145e20:
  pcVar12 = pcStack_98;
  pcVar20 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar16 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar16;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  pcVar16 = _PyRuntime_exref;
  *(longlong **)(pcVar20 + 0x18) = plVar23;
  *plVar23 = *plVar23 + 1;
  lVar11 = *(longlong *)(pcVar16 + 0x1f8);
  *(undefined4 *)(pcVar20 + 0x24) = uVar24;
  *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
  lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
  lVar1 = *(longlong *)(pcVar20 + -8);
  puVar2 = *(undefined8 **)(lVar11 + 8);
  *puVar2 = pcVar20 + -0x10;
  *(longlong *)(pcVar20 + -0x10) = lVar11;
  *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
  *(code **)(lVar11 + 8) = pcVar20 + -0x10;
  *(code **)(pcVar20 + 0x10) = pcVar12;
  *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
  if ((pcStack_98 != (code *)0x0) &&
     (*(longlong *)pcStack_98 = *(longlong *)pcStack_98 + -1, *(longlong *)pcStack_98 == 0)) {
    (**(code **)(*(longlong *)(pcStack_98 + 8) + 0x30))();
  }
LAB_23e145aa0:
  pcStack_98 = pcVar20;
  FUN_23e8bba40(plVar23,&DAT_23ec5a149,plVar8,plVar9,pcVar21,pcVar13);
  if (_DAT_23eeaaf58 == plVar23) {
    *plVar23 = *plVar23 + -1;
    if (*plVar23 == 0) {
      (**(code **)(plVar23[1] + 0x30))(plVar23);
    }
    _DAT_23eeaaf58 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar23 = *(longlong **)(lVar11 + 0x28);
  plVar10 = (longlong *)plVar23[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar23 + 8) = 0xffffffff;
  if (plVar10 != (longlong *)0x0) {
    plVar23[2] = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  *plVar23 = *plVar23 + -1;
  if (*plVar23 == 0) {
    (**(code **)(plVar23[1] + 0x30))(plVar23);
  }
  pcVar12 = pcStack_98;
  pcVar20 = pcStack_a0;
  auVar18 = auStack_a8;
  plVar23[0xf] = 0;
  _auStack_a8 = (undefined1  [16])0x0;
  pcStack_98 = (code *)0x0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((pcVar21 != (code *)0x0) &&
     (*(longlong *)pcVar21 = *(longlong *)pcVar21 + -1, *(longlong *)pcVar21 == 0)) {
    (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
  }
  if ((pcVar13 != (code *)0x0) &&
     (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0)) {
    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
  }
  _auStack_a8 = CONCAT88(pcVar20,auVar18);
  pcStack_98 = pcVar12;
  FUN_23a33aa70(param_1,auVar18,pcVar20,pcVar12);
  return 0;
}
