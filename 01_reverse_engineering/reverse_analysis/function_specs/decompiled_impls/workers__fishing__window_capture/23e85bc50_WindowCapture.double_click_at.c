/* ===== 23e85bc50 workers.fishing.window_capture:121 ===== */
/* ghidra_name=FUN_23e85bc50 entry=23e85bc50 size=4740 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e85bc50(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined1 auVar5 [16];
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  code *pcVar15;
  code *pcVar16;
  code *pcVar17;
  longlong *plVar18;
  undefined4 uVar19;
  undefined1 auVar20 [8];
  code *pcStack_b8;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  undefined1 auStack_78 [8];
  code *pcStack_70;
  code *pcStack_68;
  
  plVar10 = _DAT_23eede280;
  plVar3 = *(longlong **)*(undefined1 (*) [16])(param_3 + 1);
  plVar4 = (longlong *)param_3[2];
  auVar5 = *(undefined1 (*) [16])(param_3 + 1);
  plVar1 = (longlong *)*param_3;
  pcStack_68 = (code *)0x0;
  auStack_78 = (undefined1  [8])0x0;
  pcStack_70 = (code *)0x0;
  if (_DAT_23eede280 == (longlong *)0x0) {
LAB_23e85bcc0:
    _DAT_23eede280 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede278,DAT_23eede308,0x28);
  }
  else {
    lVar11 = *_DAT_23eede280;
    if (1 < lVar11) {
      *_DAT_23eede280 = lVar11 + -1;
      goto LAB_23e85bcc0;
    }
    if (_DAT_23eede280[2] != 0) {
      *_DAT_23eede280 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e85bcc0;
    }
  }
  plVar2 = _DAT_23eede280;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eede280 + 9;
  lVar14 = *(longlong *)(lVar11 + 8);
  _DAT_23eede280[0xf] = lVar14;
  *(longlong **)(lVar11 + 8) = plVar10;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  uVar6 = DAT_23eedb788;
  *(undefined4 *)(plVar2 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar6);
  if (plVar10 == (longlong *)0x0) {
LAB_23e85c280:
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_70 = *(code **)(param_1 + 0x68);
    pcStack_68 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_68 != (code *)0x0) {
      plVar10 = *(longlong **)(pcStack_68 + 0x18);
      goto joined_r0x00023e85c2b6;
    }
LAB_23e85c8d0:
    plVar12 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar19 = 0x7b;
    pcStack_b8 = _PyRuntime_exref;
LAB_23e85c8f3:
    pcVar16 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar17 = pcStack_68;
    }
    else {
      pcVar17 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar17;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar17 = (code *)0x0;
    }
    *(longlong *)(pcVar16 + 0x10) = 0;
    *(longlong **)(pcVar16 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar11 = *(longlong *)(pcStack_b8 + 0x1f8);
    *(undefined4 *)(pcVar16 + 0x24) = uVar19;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar14 = *(longlong *)(pcVar16 + -8);
    plVar13 = *(longlong **)(lVar11 + 8);
    *plVar13 = (longlong)(pcVar16 + -0x10);
    *(longlong *)(pcVar16 + -0x10) = lVar11;
    *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar13;
    *(code **)(lVar11 + 8) = pcVar16 + -0x10;
    if ((pcVar17 != (code *)0x0) &&
       (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
      (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
    }
    goto LAB_23e85c387;
  }
  iVar8 = FUN_23a35f020(plVar10);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if (iVar8 == -1) goto LAB_23e85c840;
  if (iVar8 == 0) {
LAB_23e85bd86:
    pcVar16 = _Py_FalseStruct_exref;
    plVar12 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
LAB_23e85bd97:
    lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar2 = *(longlong **)(lVar11 + 0x28);
    plVar13 = (longlong *)plVar2[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
    *(undefined4 *)(plVar2 + 8) = 0xffffffff;
    if (plVar13 != (longlong *)0x0) {
      plVar2[2] = 0;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))();
      }
    }
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    plVar2[0xf] = 0;
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar12 == (longlong *)0x0) goto LAB_23e85be13;
LAB_23e85be02:
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
LAB_23e85be13:
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    *plVar4 = *plVar4 + -1;
    if (*plVar4 != 0) {
      return pcVar16;
    }
    (**(code **)(plVar4[1] + 0x30))(plVar4);
    return pcVar16;
  }
  lVar11 = FUN_23e8da870();
  if (lVar11 == 0) {
    FUN_23e915740(param_1,auStack_78,DAT_23eedb7b8);
    if (pcStack_68 == (code *)0x0) goto LAB_23e85c8d0;
    plVar10 = *(longlong **)(pcStack_68 + 0x18);
joined_r0x00023e85c2b6:
    if (plVar2 == plVar10) {
      plVar12 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      pcVar16 = pcStack_68;
      goto LAB_23e85c387;
    }
    plVar12 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar19 = 0x7b;
    pcStack_b8 = _PyRuntime_exref;
  }
  else {
    plVar10 = (longlong *)FUN_23e8bc2f0(lVar11,DAT_23eedb810);
    if (plVar10 == (longlong *)0x0) goto LAB_23e85c280;
    plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedb788);
    if (plVar12 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (pcStack_68 == (code *)0x0) goto LAB_23e85c8d0;
      plVar10 = *(longlong **)(pcStack_68 + 0x18);
      goto joined_r0x00023e85c2b6;
    }
    *(undefined4 *)(plVar2 + 5) = 0x7b;
    plVar13 = (longlong *)FUN_23e914090(param_1,plVar10,plVar12);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 == (longlong *)0x0) {
LAB_23e85c840:
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcStack_68 == (code *)0x0) goto LAB_23e85c8d0;
      plVar10 = *(longlong **)(pcStack_68 + 0x18);
      goto joined_r0x00023e85c2b6;
    }
    uVar9 = FUN_23a35f020(plVar13);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (uVar9 == 0xffffffff) goto LAB_23e85c840;
    if ((uVar9 & 1) == 0) goto LAB_23e85bd86;
    *(undefined4 *)(plVar2 + 5) = 0x7e;
    auStack_98 = auVar5;
    plVar10 = (longlong *)FUN_23e954670(param_1,plVar1,DAT_23eedb938,auStack_98);
    if (plVar10 != (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a388310(plVar10);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar13 == (longlong *)0x0) goto LAB_23e85c8a0;
      plVar10 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
      if (plVar10 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,2);
        plVar12 = (longlong *)0x0;
        if (plVar10 != (longlong *)0x0) goto LAB_23e85bfea;
LAB_23e85c4f0:
        pcVar16 = pcStack_68;
        pcVar17 = pcStack_70;
        auVar20 = auStack_78;
        pcStack_68 = (code *)0x0;
        _auStack_78 = (undefined1  [16])0x0;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        pcStack_68 = (code *)0x0;
        auStack_78 = (undefined1  [8])0x0;
        pcStack_70 = (code *)0x0;
        if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        goto LAB_23e85c57a;
      }
LAB_23e85bfea:
      plVar12 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
      if (((plVar12 == (longlong *)0x0) &&
          (plVar12 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,2), plVar12 == (longlong *)0x0))
         || (cVar7 = FUN_23a3884a0(param_1,auStack_78,plVar13,2), cVar7 == '\0'))
      goto LAB_23e85c4f0;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      lVar11 = FUN_23e8da9a0();
      if (lVar11 == 0) {
        FUN_23e915740(param_1,auStack_78,DAT_23eedb790);
LAB_23e85cd66:
        uVar19 = 0x7f;
        goto LAB_23e85c596;
      }
      *(undefined4 *)(plVar2 + 5) = 0x7f;
      auStack_98._8_8_ = plVar12;
      auStack_98._0_8_ = plVar10;
      plVar13 = (longlong *)FUN_23e954670(param_1,lVar11,DAT_23eedb940,auStack_98);
      if (plVar13 == (longlong *)0x0) {
        pcStack_68 = *(code **)(param_1 + 0x70);
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e85cd66;
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      lVar14 = FUN_23e8da330();
      lVar11 = DAT_23eedb958;
      if (lVar14 == 0) {
        FUN_23e915740(param_1,auStack_78,DAT_23eedb948);
        uVar19 = 0x80;
        goto LAB_23e85c596;
      }
      *(undefined4 *)(plVar2 + 5) = 0x80;
      plVar13 = (longlong *)
                FUN_23e915840(param_1,lVar14,DAT_23eedb950,*(undefined8 *)(lVar11 + 0x18));
      if (plVar13 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_68 = *(code **)(param_1 + 0x70);
        uVar19 = 0x80;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_70 = *(code **)(param_1 + 0x68);
        goto LAB_23e85c596;
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      lVar11 = FUN_23e8da9a0();
      if (lVar11 == 0) {
        FUN_23e915740(param_1,auStack_78,DAT_23eedb790);
        uVar19 = 0x81;
        goto LAB_23e85c596;
      }
      *(undefined4 *)(plVar2 + 5) = 0x81;
      plVar13 = (longlong *)FUN_23e91bfe0(param_1,lVar11,_DAT_23eedb980);
      if (plVar13 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_68 = *(code **)(param_1 + 0x70);
        uVar19 = 0x81;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_70 = *(code **)(param_1 + 0x68);
        goto LAB_23e85c596;
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      lVar14 = FUN_23e8da330();
      lVar11 = _DAT_23eedb988;
      if (lVar14 == 0) {
        FUN_23e915740(param_1,auStack_78,DAT_23eedb948);
        uVar19 = 0x82;
        goto LAB_23e85c596;
      }
      *(undefined4 *)(plVar2 + 5) = 0x82;
      plVar13 = (longlong *)
                FUN_23e915840(param_1,lVar14,DAT_23eedb950,*(undefined8 *)(lVar11 + 0x18));
      if (plVar13 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_68 = *(code **)(param_1 + 0x70);
        uVar19 = 0x82;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_70 = *(code **)(param_1 + 0x68);
        goto LAB_23e85c596;
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      lVar11 = FUN_23e8da9a0();
      if (lVar11 == 0) {
        FUN_23e915740(param_1,auStack_78,DAT_23eedb790);
        uVar19 = 0x83;
        goto LAB_23e85c596;
      }
      *(undefined4 *)(plVar2 + 5) = 0x83;
      plVar13 = (longlong *)FUN_23e91bfe0(param_1,lVar11,_DAT_23eedb980);
      if (plVar13 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_68 = *(code **)(param_1 + 0x70);
        uVar19 = 0x83;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_70 = *(code **)(param_1 + 0x68);
        goto LAB_23e85c596;
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      lVar14 = FUN_23e8da330();
      lVar11 = DAT_23eedb958;
      if (lVar14 == 0) {
        FUN_23e915740(param_1,auStack_78,DAT_23eedb948);
        uVar19 = 0x84;
        goto LAB_23e85c596;
      }
      *(undefined4 *)(plVar2 + 5) = 0x84;
      plVar13 = (longlong *)
                FUN_23e915840(param_1,lVar14,DAT_23eedb950,*(undefined8 *)(lVar11 + 0x18));
      if (plVar13 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_68 = *(code **)(param_1 + 0x70);
        uVar19 = 0x84;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_70 = *(code **)(param_1 + 0x68);
        goto LAB_23e85c596;
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar2 = *(longlong **)(lVar11 + 0x28);
      plVar13 = (longlong *)plVar2[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
      *(undefined4 *)(plVar2 + 8) = 0xffffffff;
      if (plVar13 != (longlong *)0x0) {
        plVar2[2] = 0;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))();
        }
      }
      *plVar2 = *plVar2 + -1;
      if (*plVar2 == 0) {
        (**(code **)(plVar2[1] + 0x30))(plVar2);
      }
      plVar2[0xf] = 0;
      pcVar16 = _Py_TrueStruct_exref;
      *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e85be02;
    }
LAB_23e85c8a0:
    auVar20 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcVar17 = *(code **)(param_1 + 0x68);
    pcVar16 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e85c57a:
    uVar19 = 0x7e;
    plVar12 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    pcStack_68 = pcVar16;
    auStack_78 = auVar20;
    pcStack_70 = pcVar17;
LAB_23e85c596:
    pcVar16 = pcStack_68;
    auStack_98._8_8_ = pcStack_70;
    auStack_98._0_8_ = auStack_78;
    pcStack_68 = (code *)0x0;
    auStack_78 = (undefined1  [8])0x0;
    pcStack_70 = (code *)0x0;
    apcStack_88[0] = pcVar16;
    plVar13 = *(longlong **)(param_1 + 0x138);
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + 1;
    }
    pcVar17 = DAT_23ed6a4f8;
    if (pcVar16 == (code *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar16 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar16;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcStack_b8 = _PyRuntime_exref;
      *(longlong *)(pcVar17 + 0x10) = 0;
      *(longlong **)(pcVar17 + 0x18) = plVar2;
      *plVar2 = *plVar2 + 1;
      lVar11 = *(longlong *)(pcStack_b8 + 0x1f8);
      *(undefined4 *)(pcVar17 + 0x24) = uVar19;
      lVar11 = *(longlong *)(lVar11 + 0x10);
      *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
      lVar11 = *(longlong *)(lVar11 + 0x2e8);
      lVar14 = *(longlong *)(pcVar17 + -8);
      plVar18 = *(longlong **)(lVar11 + 8);
      *plVar18 = (longlong)(pcVar17 + -0x10);
      *(longlong *)(pcVar17 + -0x10) = lVar11;
      *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar18;
      *(code **)(lVar11 + 8) = pcVar17 + -0x10;
      if ((apcStack_88[0] != (code *)0x0) &&
         (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
         *(longlong *)apcStack_88[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar15 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcStack_b8 = _PyRuntime_exref;
      *(longlong **)(pcVar17 + 0x18) = plVar2;
      *plVar2 = *plVar2 + 1;
      lVar11 = *(longlong *)(pcStack_b8 + 0x1f8);
      *(undefined4 *)(pcVar17 + 0x24) = uVar19;
      lVar11 = *(longlong *)(lVar11 + 0x10);
      *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
      lVar11 = *(longlong *)(lVar11 + 0x2e8);
      lVar14 = *(longlong *)(pcVar17 + -8);
      plVar18 = *(longlong **)(lVar11 + 8);
      *plVar18 = (longlong)(pcVar17 + -0x10);
      *(longlong *)(pcVar17 + -0x10) = lVar11;
      *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar18;
      *(code **)(lVar11 + 8) = pcVar17 + -0x10;
      *(code **)(pcVar17 + 0x10) = pcVar16;
      *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
      if ((apcStack_88[0] != (code *)0x0) &&
         (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
         *(longlong *)apcStack_88[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
      }
    }
    pcVar15 = _Py_NoneStruct_exref;
    apcStack_88[0] = pcVar17;
    if (((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) &&
       ((code *)auStack_98._0_8_ != (code *)0x0)) {
      FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
    }
    plVar18 = *(longlong **)(auStack_98._8_8_ + 0x28);
    if (apcStack_88[0] == pcVar15) {
      pcVar16 = (code *)0x0;
    }
    else {
      pcVar16 = apcStack_88[0];
      if (apcStack_88[0] != (code *)0x0) {
        *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
      }
    }
    *(code **)(auStack_98._8_8_ + 0x28) = pcVar16;
    if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
      (**(code **)(plVar18[1] + 0x30))();
    }
    plVar18 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
    if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
      (**(code **)(plVar18[1] + 0x30))();
    }
    *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
    if (*(longlong *)auStack_98._0_8_ == 0) {
      (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
    }
    if ((apcStack_88[0] != (code *)0x0) &&
       (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
       *(longlong *)apcStack_88[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
    }
    apcStack_88[0] = (code *)0x0;
    auStack_98 = (undefined1  [16])0x0;
    iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                          *(undefined8 *)PyExc_Exception_exref);
    pcVar16 = _Py_FalseStruct_exref;
    if (iVar8 != 0) {
      plVar2 = *(longlong **)(param_1 + 0x138);
      *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
      *(longlong **)(param_1 + 0x138) = plVar13;
      if ((plVar2 != (longlong *)0x0) && (*plVar2 = *plVar2 + -1, *plVar2 == 0)) {
        (**(code **)(plVar2[1] + 0x30))();
      }
      goto LAB_23e85bd97;
    }
    pcVar17 = *(code **)(param_1 + 0x138);
    pcStack_70 = pcVar17;
    if ((pcVar17 == (code *)0x0) || (pcVar17 == pcVar15)) {
      plVar18 = *(longlong **)PyExc_RuntimeError_exref;
      pcVar15 = (code *)PyUnicode_FromString("No active exception to reraise");
      pcVar17 = *(code **)(param_1 + 0x138);
      *plVar18 = *plVar18 + 1;
      *(longlong **)(param_1 + 0x138) = plVar13;
      auStack_78 = (undefined1  [8])plVar18;
      pcStack_70 = pcVar15;
      if (pcVar17 != (code *)0x0) {
        iVar8 = 0x7d;
        pcVar16 = (code *)0x0;
        goto LAB_23e85cadf;
      }
LAB_23e85cbec:
      pcStack_68 = (code *)0x0;
      uVar19 = 0x7d;
      goto LAB_23e85c8f3;
    }
    plVar18 = *(longlong **)(pcVar17 + 8);
    pcVar16 = *(code **)(pcVar17 + 0x28);
    *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
    *plVar18 = *plVar18 + 1;
    iVar8 = 0;
    pcVar15 = pcVar17;
    if (pcVar16 == (code *)0x0) {
      *(longlong **)(param_1 + 0x138) = plVar13;
    }
    else {
      *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
      if (*(longlong **)(pcVar16 + 0x18) == plVar2) {
        *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcVar16 + 0x24);
      }
      *(longlong **)(param_1 + 0x138) = plVar13;
    }
LAB_23e85cadf:
    pcStack_68 = (code *)0x0;
    _auStack_78 = (undefined1  [16])0x0;
    *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
    if (*(longlong *)pcVar17 == 0) {
      (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
    }
    auStack_78 = (undefined1  [8])plVar18;
    pcStack_70 = pcVar15;
    if (pcVar16 == (code *)0x0) {
      pcStack_68 = (code *)0x0;
      if (iVar8 != 0) goto LAB_23e85cbec;
      uVar19 = (undefined4)plVar2[5];
      goto LAB_23e85c8f3;
    }
    if (*(longlong **)(pcVar16 + 0x18) == plVar2) goto LAB_23e85c387;
    pcStack_68 = pcVar16;
    if (iVar8 == 0) {
      uVar19 = (undefined4)plVar2[5];
    }
    else {
      uVar19 = 0x7d;
    }
  }
  pcVar17 = pcStack_68;
  pcVar16 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar15 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar15;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar16 + 0x18) = plVar2;
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(pcVar16 + 0x24) = uVar19;
  *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
  lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_b8 + 0x1f8) + 0x10) + 0x2e8);
  lVar14 = *(longlong *)(pcVar16 + -8);
  plVar13 = *(longlong **)(lVar11 + 8);
  *plVar13 = (longlong)(pcVar16 + -0x10);
  *(longlong *)(pcVar16 + -0x10) = lVar11;
  *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar13;
  *(code **)(lVar11 + 8) = pcVar16 + -0x10;
  *(code **)(pcVar16 + 0x10) = pcVar17;
  *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
  if ((pcStack_68 != (code *)0x0) &&
     (*(longlong *)pcStack_68 = *(longlong *)pcStack_68 + -1, *(longlong *)pcStack_68 == 0)) {
    (**(code **)(*(longlong *)(pcStack_68 + 8) + 0x30))();
  }
LAB_23e85c387:
  pcStack_68 = pcVar16;
  FUN_23e8bba40(plVar2,"ooooo",plVar1,plVar3,plVar4,plVar10,plVar12);
  if (_DAT_23eede280 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eede280 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar11 + 0x28);
  plVar13 = (longlong *)plVar2[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  pcVar17 = pcStack_68;
  pcVar16 = pcStack_70;
  auVar20 = auStack_78;
  plVar2[0xf] = 0;
  _auStack_78 = (undefined1  [16])0x0;
  pcStack_68 = (code *)0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  _auStack_78 = CONCAT88(pcVar16,auVar20);
  *plVar1 = *plVar1 + -1;
  pcStack_68 = pcVar17;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  FUN_23a33aa70(param_1,auStack_78,pcStack_70,pcStack_68);
  return (code *)0x0;
}
