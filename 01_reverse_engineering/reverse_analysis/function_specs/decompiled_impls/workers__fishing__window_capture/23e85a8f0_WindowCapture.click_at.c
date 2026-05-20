/* ===== 23e85a8f0 workers.fishing.window_capture:104 ===== */
/* ghidra_name=FUN_23e85a8f0 entry=23e85a8f0 size=4813 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e85a8f0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined1 auVar6 [16];
  undefined8 uVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  code *pcVar16;
  code *pcVar17;
  code *pcVar18;
  undefined4 uVar19;
  longlong *plVar20;
  undefined1 auVar21 [8];
  code *local_b8;
  undefined1 local_98 [16];
  code *local_88 [2];
  undefined1 local_78 [8];
  code *pcStack_70;
  code *local_68;
  
  plVar11 = DAT_23eede290;
  plVar4 = *(longlong **)*(undefined1 (*) [16])(param_3 + 1);
  plVar5 = (longlong *)param_3[2];
  auVar6 = *(undefined1 (*) [16])(param_3 + 1);
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[3];
  local_68 = (code *)0x0;
  local_78 = (undefined1  [8])0x0;
  pcStack_70 = (code *)0x0;
  if (DAT_23eede290 == (longlong *)0x0) {
LAB_23e85a961:
    DAT_23eede290 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede288,DAT_23eede308,0x30);
  }
  else {
    lVar12 = *DAT_23eede290;
    if (1 < lVar12) {
      *DAT_23eede290 = lVar12 + -1;
      goto LAB_23e85a961;
    }
    if (DAT_23eede290[2] != 0) {
      *DAT_23eede290 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e85a961;
    }
  }
  plVar3 = DAT_23eede290;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar11 = DAT_23eede290 + 9;
  lVar15 = *(longlong *)(lVar12 + 8);
  DAT_23eede290[0xf] = lVar15;
  *(longlong **)(lVar12 + 8) = plVar11;
  if ((lVar15 != 0) &&
     (((*(char *)(lVar15 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar15 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar15 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar15 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar15 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar7 = DAT_23eedb788;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,uVar7);
  if (plVar11 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_70 = *(code **)(param_1 + 0x68);
    local_68 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_68 == (code *)0x0) goto LAB_23e85b550;
LAB_23e85b20a:
    plVar11 = *(longlong **)(local_68 + 0x18);
joined_r0x00023e85b20e:
    if (plVar11 == plVar3) {
      plVar13 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      pcVar17 = local_68;
      goto LAB_23e85b2df;
    }
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    uVar19 = 0x6a;
    local_b8 = _PyRuntime_exref;
LAB_23e85b234:
    pcVar18 = local_68;
    pcVar17 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar16 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar17 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    *(undefined4 *)(pcVar17 + 0x24) = uVar19;
    *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(local_b8 + 0x1f8) + 0x10) + 0x2e8);
    lVar15 = *(longlong *)(pcVar17 + -8);
    plVar14 = *(longlong **)(lVar12 + 8);
    *plVar14 = (longlong)(pcVar17 + -0x10);
    *(longlong *)(pcVar17 + -0x10) = lVar12;
    *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)plVar14;
    *(code **)(lVar12 + 8) = pcVar17 + -0x10;
    *(code **)(pcVar17 + 0x10) = pcVar18;
    *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
    if ((local_68 != (code *)0x0) &&
       (*(longlong *)local_68 = *(longlong *)local_68 + -1, *(longlong *)local_68 == 0)) {
      (**(code **)(*(longlong *)(local_68 + 8) + 0x30))();
    }
    goto LAB_23e85b2df;
  }
  iVar9 = FUN_23a35f020(plVar11);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (iVar9 == -1) {
    local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_70 = *(code **)(param_1 + 0x68);
    local_68 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_68 != (code *)0x0) {
      plVar11 = *(longlong **)(local_68 + 0x18);
      goto joined_r0x00023e85b20e;
    }
    goto LAB_23e85b550;
  }
  if (iVar9 == 0) {
LAB_23e85aa27:
    pcVar17 = _Py_FalseStruct_exref;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
LAB_23e85aa37:
    lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar3 = *(longlong **)(lVar12 + 0x28);
    plVar14 = (longlong *)plVar3[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
    *(undefined4 *)(plVar3 + 8) = 0xffffffff;
    if (plVar14 != (longlong *)0x0) {
      plVar3[2] = 0;
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))();
      }
    }
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    plVar3[0xf] = 0;
    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar13 == (longlong *)0x0) goto LAB_23e85aab3;
LAB_23e85aaa2:
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
LAB_23e85aab3:
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    lVar12 = *plVar5;
    *plVar5 = lVar12 + -1;
    if (lVar12 + -1 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    *plVar2 = *plVar2 + -1;
    if (*plVar2 != 0) {
      return pcVar17;
    }
    (**(code **)(plVar2[1] + 0x30))(plVar2);
    return pcVar17;
  }
  lVar12 = FUN_23e8da870();
  if (lVar12 == 0) {
    FUN_23e915740(param_1,local_78,DAT_23eedb7b8);
    if (local_68 != (code *)0x0) goto LAB_23e85b20a;
LAB_23e85b550:
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    uVar19 = 0x6a;
    local_b8 = _PyRuntime_exref;
  }
  else {
    plVar11 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23eedb810);
    if (plVar11 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      local_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (local_68 != (code *)0x0) {
        plVar11 = *(longlong **)(local_68 + 0x18);
        goto joined_r0x00023e85b20e;
      }
      goto LAB_23e85b550;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedb788);
    if (plVar13 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      local_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (local_68 != (code *)0x0) {
        plVar11 = *(longlong **)(local_68 + 0x18);
        goto joined_r0x00023e85b20e;
      }
      goto LAB_23e85b550;
    }
    *(undefined4 *)(plVar3 + 5) = 0x6a;
    plVar14 = (longlong *)FUN_23e914090(param_1,plVar11,plVar13);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (plVar14 == (longlong *)0x0) {
LAB_23e85b4e0:
      local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      local_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (local_68 != (code *)0x0) {
        plVar11 = *(longlong **)(local_68 + 0x18);
        goto joined_r0x00023e85b20e;
      }
      goto LAB_23e85b550;
    }
    uVar10 = FUN_23a35f020(plVar14);
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if (uVar10 == 0xffffffff) goto LAB_23e85b4e0;
    if ((uVar10 & 1) == 0) goto LAB_23e85aa27;
    *(undefined4 *)(plVar3 + 5) = 0x6d;
    local_98 = auVar6;
    plVar11 = (longlong *)FUN_23e954670(param_1,plVar1,DAT_23eedb938,local_98);
    if (plVar11 != (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a388310(plVar11);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar14 == (longlong *)0x0) goto LAB_23e85b4c0;
      plVar11 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
      if (plVar11 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a3c1b70(param_1,local_78,0,2);
        plVar13 = (longlong *)0x0;
        if (plVar11 != (longlong *)0x0) goto LAB_23e85aca6;
LAB_23e85aef0:
        pcVar17 = local_68;
        pcVar18 = pcStack_70;
        auVar21 = local_78;
        local_68 = (code *)0x0;
        _local_78 = (undefined1  [16])0x0;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        local_68 = (code *)0x0;
        local_78 = (undefined1  [8])0x0;
        pcStack_70 = (code *)0x0;
        if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        goto LAB_23e85af7a;
      }
LAB_23e85aca6:
      plVar13 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
      if (((plVar13 == (longlong *)0x0) &&
          (plVar13 = (longlong *)FUN_23a3c1b70(param_1,local_78,1,2), plVar13 == (longlong *)0x0))
         || (cVar8 = FUN_23a3884a0(param_1,local_78,plVar14,2), cVar8 == '\0')) goto LAB_23e85aef0;
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      lVar12 = FUN_23e8da9a0();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,local_78,DAT_23eedb790);
LAB_23e85ba67:
        uVar19 = 0x6e;
        goto LAB_23e85af94;
      }
      *(undefined4 *)(plVar3 + 5) = 0x6e;
      local_98._8_8_ = plVar13;
      local_98._0_8_ = plVar11;
      plVar14 = (longlong *)FUN_23e954670(param_1,lVar12,DAT_23eedb940,local_98);
      if (plVar14 == (longlong *)0x0) {
        local_68 = *(code **)(param_1 + 0x70);
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e85ba67;
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      lVar15 = FUN_23e8da330();
      lVar12 = DAT_23eedb958;
      if (lVar15 == 0) {
        FUN_23e915740(param_1,local_78,DAT_23eedb948);
        uVar19 = 0x6f;
        goto LAB_23e85af94;
      }
      *(undefined4 *)(plVar3 + 5) = 0x6f;
      plVar14 = (longlong *)
                FUN_23e915840(param_1,lVar15,DAT_23eedb950,*(undefined8 *)(lVar12 + 0x18));
      if (plVar14 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        local_68 = *(code **)(param_1 + 0x70);
        uVar19 = 0x6f;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_70 = *(code **)(param_1 + 0x68);
        goto LAB_23e85af94;
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      iVar9 = FUN_23e913250(plVar2,DAT_23eedb960);
      if (iVar9 == -1) {
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        local_68 = *(code **)(param_1 + 0x70);
        uVar19 = 0x70;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_70 = *(code **)(param_1 + 0x68);
        goto LAB_23e85af94;
      }
      if (iVar9 == 1) {
        lVar12 = FUN_23e8da9a0();
        if (lVar12 == 0) {
          FUN_23e915740(param_1,local_78,DAT_23eedb790);
          uVar19 = 0x71;
        }
        else {
          *(undefined4 *)(plVar3 + 5) = 0x71;
          plVar14 = (longlong *)FUN_23e91bfe0(param_1,lVar12,DAT_23eedb968);
          if (plVar14 != (longlong *)0x0) goto LAB_23e85adfc;
          local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          local_68 = *(code **)(param_1 + 0x70);
          uVar19 = 0x71;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcStack_70 = *(code **)(param_1 + 0x68);
        }
        goto LAB_23e85af94;
      }
      lVar12 = FUN_23e8da9a0();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,local_78,DAT_23eedb790);
        uVar19 = 0x73;
        goto LAB_23e85af94;
      }
      *(undefined4 *)(plVar3 + 5) = 0x73;
      plVar14 = (longlong *)FUN_23e91bfe0(param_1,lVar12,DAT_23eedb970);
      if (plVar14 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        local_68 = *(code **)(param_1 + 0x70);
        uVar19 = 0x73;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_70 = *(code **)(param_1 + 0x68);
        goto LAB_23e85af94;
      }
LAB_23e85adfc:
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))();
      }
      lVar15 = FUN_23e8da330();
      lVar12 = DAT_23eedb958;
      if (lVar15 == 0) {
        FUN_23e915740(param_1,local_78,DAT_23eedb948);
        uVar19 = 0x74;
        goto LAB_23e85af94;
      }
      *(undefined4 *)(plVar3 + 5) = 0x74;
      plVar14 = (longlong *)
                FUN_23e915840(param_1,lVar15,DAT_23eedb950,*(undefined8 *)(lVar12 + 0x18));
      if (plVar14 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        local_68 = *(code **)(param_1 + 0x70);
        uVar19 = 0x74;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_70 = *(code **)(param_1 + 0x68);
        goto LAB_23e85af94;
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar3 = *(longlong **)(lVar12 + 0x28);
      plVar14 = (longlong *)plVar3[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
      *(undefined4 *)(plVar3 + 8) = 0xffffffff;
      if (plVar14 != (longlong *)0x0) {
        plVar3[2] = 0;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))();
        }
      }
      *plVar3 = *plVar3 + -1;
      if (*plVar3 == 0) {
        (**(code **)(plVar3[1] + 0x30))(plVar3);
      }
      plVar3[0xf] = 0;
      pcVar17 = _Py_TrueStruct_exref;
      *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e85aaa2;
    }
LAB_23e85b4c0:
    auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcVar18 = *(code **)(param_1 + 0x68);
    pcVar17 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e85af7a:
    plVar13 = (longlong *)0x0;
    uVar19 = 0x6d;
    plVar11 = (longlong *)0x0;
    local_68 = pcVar17;
    local_78 = auVar21;
    pcStack_70 = pcVar18;
LAB_23e85af94:
    pcVar17 = local_68;
    local_98._8_8_ = pcStack_70;
    local_98._0_8_ = local_78;
    local_68 = (code *)0x0;
    local_78 = (undefined1  [8])0x0;
    pcStack_70 = (code *)0x0;
    local_88[0] = pcVar17;
    plVar14 = *(longlong **)(param_1 + 0x138);
    if (plVar14 != (longlong *)0x0) {
      *plVar14 = *plVar14 + 1;
    }
    pcVar18 = DAT_23ed6a4f8;
    if (pcVar17 == (code *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar17 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar17;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar18 + 0x10) = 0;
      *(longlong **)(pcVar18 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      *(undefined4 *)(pcVar18 + 0x24) = uVar19;
      local_b8 = _PyRuntime_exref;
      *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
      lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(local_b8 + 0x1f8) + 0x10) + 0x2e8);
      lVar15 = *(longlong *)(pcVar18 + -8);
      plVar20 = *(longlong **)(lVar12 + 8);
      *plVar20 = (longlong)(pcVar18 + -0x10);
      *(longlong *)(pcVar18 + -0x10) = lVar12;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)plVar20;
      *(code **)(lVar12 + 8) = pcVar18 + -0x10;
      if ((local_88[0] != (code *)0x0) &&
         (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0))
      {
        (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar16 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar16;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar18 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      *(undefined4 *)(pcVar18 + 0x24) = uVar19;
      local_b8 = _PyRuntime_exref;
      *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
      lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(local_b8 + 0x1f8) + 0x10) + 0x2e8);
      lVar15 = *(longlong *)(pcVar18 + -8);
      plVar20 = *(longlong **)(lVar12 + 8);
      *plVar20 = (longlong)(pcVar18 + -0x10);
      *(longlong *)(pcVar18 + -0x10) = lVar12;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)plVar20;
      *(code **)(lVar12 + 8) = pcVar18 + -0x10;
      *(code **)(pcVar18 + 0x10) = pcVar17;
      *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
      if ((local_88[0] != (code *)0x0) &&
         (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0))
      {
        (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
      }
    }
    pcVar16 = _Py_NoneStruct_exref;
    local_88[0] = pcVar18;
    if (((code *)local_98._0_8_ != _Py_NoneStruct_exref) && ((code *)local_98._0_8_ != (code *)0x0))
    {
      FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
    }
    plVar20 = *(longlong **)(local_98._8_8_ + 0x28);
    if (local_88[0] == pcVar16) {
      pcVar17 = (code *)0x0;
    }
    else {
      pcVar17 = local_88[0];
      if (local_88[0] != (code *)0x0) {
        *(longlong *)local_88[0] = *(longlong *)local_88[0] + 1;
      }
    }
    *(code **)(local_98._8_8_ + 0x28) = pcVar17;
    if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
      (**(code **)(plVar20[1] + 0x30))();
    }
    plVar20 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
    if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
      (**(code **)(plVar20[1] + 0x30))();
    }
    *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
    if (*(longlong *)local_98._0_8_ == 0) {
      (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
    }
    if ((local_88[0] != (code *)0x0) &&
       (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)) {
      (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
    }
    local_88[0] = (code *)0x0;
    local_98 = (undefined1  [16])0x0;
    iVar9 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                          *(undefined8 *)PyExc_Exception_exref);
    pcVar17 = _Py_FalseStruct_exref;
    if (iVar9 != 0) {
      plVar3 = *(longlong **)(param_1 + 0x138);
      *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
      *(longlong **)(param_1 + 0x138) = plVar14;
      if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
        (**(code **)(plVar3[1] + 0x30))();
      }
      goto LAB_23e85aa37;
    }
    pcVar18 = *(code **)(param_1 + 0x138);
    pcStack_70 = pcVar18;
    if ((pcVar18 != pcVar16) && (pcVar18 != (code *)0x0)) {
      plVar20 = *(longlong **)(pcVar18 + 8);
      pcVar17 = *(code **)(pcVar18 + 0x28);
      *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
      *plVar20 = *plVar20 + 1;
      iVar9 = 0;
      pcVar16 = pcVar18;
      if (pcVar17 == (code *)0x0) {
        *(longlong **)(param_1 + 0x138) = plVar14;
      }
      else {
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
        if (*(longlong **)(pcVar17 + 0x18) == plVar3) {
          *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar17 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar14;
      }
LAB_23e85b75f:
      local_68 = (code *)0x0;
      _local_78 = (undefined1  [16])0x0;
      *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
      if (*(longlong *)pcVar18 == 0) {
        (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
      }
      local_78 = (undefined1  [8])plVar20;
      pcStack_70 = pcVar16;
      if (pcVar17 == (code *)0x0) {
        local_68 = (code *)0x0;
        if (iVar9 != 0) goto LAB_23e85b8dc;
        uVar19 = (undefined4)plVar3[5];
        goto LAB_23e85b572;
      }
      if (*(longlong **)(pcVar17 + 0x18) == plVar3) goto LAB_23e85b2df;
      local_68 = pcVar17;
      if (iVar9 == 0) {
        uVar19 = (undefined4)plVar3[5];
      }
      else {
        uVar19 = 0x6c;
      }
      goto LAB_23e85b234;
    }
    plVar20 = *(longlong **)PyExc_RuntimeError_exref;
    pcVar16 = (code *)PyUnicode_FromString("No active exception to reraise");
    pcVar18 = *(code **)(param_1 + 0x138);
    *plVar20 = *plVar20 + 1;
    *(longlong **)(param_1 + 0x138) = plVar14;
    local_78 = (undefined1  [8])plVar20;
    pcStack_70 = pcVar16;
    if (pcVar18 != (code *)0x0) {
      iVar9 = 0x6c;
      pcVar17 = (code *)0x0;
      goto LAB_23e85b75f;
    }
LAB_23e85b8dc:
    local_68 = (code *)0x0;
    uVar19 = 0x6c;
  }
LAB_23e85b572:
  pcVar17 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    pcVar18 = local_68;
  }
  else {
    pcVar18 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar18;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    pcVar18 = (code *)0x0;
  }
  *(longlong *)(pcVar17 + 0x10) = 0;
  *(longlong **)(pcVar17 + 0x18) = plVar3;
  *plVar3 = *plVar3 + 1;
  lVar12 = *(longlong *)(local_b8 + 0x1f8);
  *(undefined4 *)(pcVar17 + 0x24) = uVar19;
  lVar12 = *(longlong *)(lVar12 + 0x10);
  *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
  lVar12 = *(longlong *)(lVar12 + 0x2e8);
  lVar15 = *(longlong *)(pcVar17 + -8);
  plVar14 = *(longlong **)(lVar12 + 8);
  *plVar14 = (longlong)(pcVar17 + -0x10);
  *(longlong *)(pcVar17 + -0x10) = lVar12;
  *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)plVar14;
  *(code **)(lVar12 + 8) = pcVar17 + -0x10;
  if ((pcVar18 != (code *)0x0) &&
     (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
  }
LAB_23e85b2df:
  local_68 = pcVar17;
  FUN_23e8bba40(plVar3,"oooooo",plVar1,plVar4,plVar5,plVar2,plVar11,plVar13);
  if (DAT_23eede290 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eede290 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar12 + 0x28);
  plVar14 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar14 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  pcVar18 = local_68;
  pcVar17 = pcStack_70;
  auVar21 = local_78;
  plVar3[0xf] = 0;
  _local_78 = (undefined1  [16])0x0;
  local_68 = (code *)0x0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  _local_78 = CONCAT88(pcVar17,auVar21);
  *plVar1 = *plVar1 + -1;
  local_68 = pcVar18;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  lVar12 = *plVar5;
  *plVar5 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_78,pcStack_70,local_68);
  return (code *)0x0;
}
