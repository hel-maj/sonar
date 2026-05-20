/* ===== 23e77a2d0 workers.fishing.fishing_bot:FishingBot._sleep ===== */
/* ghidra_name=FUN_23e77a2d0 entry=23e77a2d0 size=2755 */

code * FUN_23e77a2d0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int iVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  code *pcVar13;
  longlong lVar14;
  longlong *plVar15;
  undefined4 uVar16;
  undefined1 local_78 [16];
  longlong *local_68 [5];
  
  plVar11 = DAT_23eedad38;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  local_68[0] = (longlong *)0x0;
  local_78._0_8_ = (code *)0x0;
  local_78._8_8_ = 0;
  if (DAT_23eedad38 == (longlong *)0x0) {
LAB_23e77a325:
    DAT_23eedad38 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedaef0,DAT_23eedaeb8,0x18);
  }
  else {
    lVar10 = *DAT_23eedad38;
    if (1 < lVar10) {
      *DAT_23eedad38 = lVar10 + -1;
      goto LAB_23e77a325;
    }
    if (DAT_23eedad38[2] != 0) {
      *DAT_23eedad38 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e77a325;
    }
  }
  plVar6 = DAT_23eedad38;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar11 = DAT_23eedad38 + 9;
  lVar14 = *(longlong *)(lVar10 + 8);
  DAT_23eedad38[0xf] = lVar14;
  *(longlong **)(lVar10 + 8) = plVar11;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar6[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  *(undefined4 *)(plVar6 + 8) = 0;
  lVar10 = FUN_23e8e0ba0();
  if (lVar10 == 0) {
    uVar16 = 0x634;
    FUN_23e915740(param_1,local_78,DAT_23eed8c70);
    plVar12 = (longlong *)0x0;
    plVar11 = local_68[0];
    plVar15 = DAT_23ed6a4f8;
    goto joined_r0x00023e77a5e7;
  }
  *(undefined4 *)(plVar6 + 5) = 0x634;
  plVar11 = (longlong *)FUN_23e91bfe0(param_1,lVar10);
  if (plVar11 == (longlong *)0x0) {
    local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0x634;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar15 = DAT_23ed6a4f8;
    goto joined_r0x00023e77a5e7;
  }
  plVar12 = (longlong *)FUN_23e8c09e0(plVar11,plVar2);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (plVar12 == (longlong *)0x0) {
    local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plVar11 = *(longlong **)(param_1 + 0x70);
    uVar16 = 0x634;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar15 = DAT_23ed6a4f8;
    goto joined_r0x00023e77a5e7;
  }
  if (plVar1 == (longlong *)0x0) {
    do {
      while( true ) {
        lVar10 = FUN_23e8e0ba0();
        uVar7 = DAT_23eed8c70;
        if (lVar10 == 0) goto LAB_23e77a8c8;
        *(undefined4 *)(plVar6 + 5) = 0x635;
        plVar11 = (longlong *)FUN_23e91bfe0(param_1,lVar10,uVar7);
        if (plVar11 == (longlong *)0x0) goto LAB_23e77a9f8;
        pcVar13 = (code *)FUN_23e8d09c0(plVar11,plVar12);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (pcVar13 == (code *)0x0) goto LAB_23e77a9f8;
        iVar9 = FUN_23a35f020(pcVar13);
        if (iVar9 == -1) goto LAB_23e77aad0;
        if (iVar9 == 1) {
          *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
          if (*(longlong *)pcVar13 == 0) {
            (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
          }
          local_78._8_8_ =
               PyUnicode_FromFormat
                         ("cannot access local variable \'%U\' where it is not associated with a value"
                          ,DAT_23eed8d30);
          local_78._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
          *(longlong *)local_78._0_8_ = *(longlong *)local_78._0_8_ + 1;
          local_68[0] = (longlong *)0x0;
          if ((code *)local_78._0_8_ != _Py_NoneStruct_exref) {
            FUN_23e91b1b0(param_1,local_78,local_78 + 8,local_68);
          }
          uVar16 = 0x635;
          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_78._8_8_);
          plVar11 = local_68[0];
          plVar15 = DAT_23ed6a4f8;
          goto joined_r0x00023e77a5e7;
        }
        iVar9 = FUN_23a35f020(pcVar13);
        *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
        if (*(longlong *)pcVar13 == 0) {
          (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
        }
        if (iVar9 == -1) goto LAB_23e77a9f8;
        if (iVar9 == 0) goto LAB_23e77ab20;
        lVar14 = FUN_23e8e0ba0();
        lVar10 = DAT_23eed8e78;
        if (lVar14 == 0) goto LAB_23e77a9d0;
        *(undefined4 *)(plVar6 + 5) = 0x636;
        plVar11 = (longlong *)
                  FUN_23e915840(param_1,lVar14,DAT_23eed8d40,*(undefined8 *)(lVar10 + 0x18));
        if (plVar11 == (longlong *)0x0) goto LAB_23e77abc0;
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        lVar10 = *(longlong *)(param_1 + 0x10);
        if (((*(int *)(*(longlong *)(lVar10 + 0x28) + 0x160) != 0) || (*(int *)(lVar10 + 0x78) != 0)
            ) && ((iVar9 = Py_MakePendingCalls(), iVar9 < 0 &&
                  (pcVar13 = *(code **)(param_1 + 0x60), pcVar13 != (code *)0x0))))
        goto LAB_23e77a5af;
        if (*(int *)(lVar10 + 0x68) != 0) break;
        plVar11 = *(longlong **)(param_1 + 0x90);
        if (plVar11 != (longlong *)0x0) goto LAB_23e77a53f;
      }
      PyEval_SaveThread();
      PyEval_AcquireThread(param_1);
      plVar11 = *(longlong **)(param_1 + 0x90);
    } while (plVar11 == (longlong *)0x0);
  }
  else {
LAB_23e77a40f:
    do {
      lVar10 = FUN_23e8e0ba0();
      if (lVar10 == 0) goto LAB_23e77a8c8;
      *(undefined4 *)(plVar6 + 5) = 0x635;
      plVar11 = (longlong *)FUN_23e91bfe0(param_1,lVar10);
      if (plVar11 == (longlong *)0x0) goto LAB_23e77a9f8;
      pcVar13 = (code *)FUN_23e8d09c0(plVar11,plVar12);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (pcVar13 == (code *)0x0) goto LAB_23e77a9f8;
      iVar9 = FUN_23a35f020(pcVar13);
      if (iVar9 == -1) goto LAB_23e77aad0;
      if (iVar9 == 1) {
        *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
        if (*(longlong *)pcVar13 == 0) {
          (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
        }
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed89b0);
        if (plVar11 == (longlong *)0x0) goto LAB_23e77a9f8;
        *(undefined4 *)(plVar6 + 5) = 0x635;
        plVar15 = (longlong *)FUN_23e91bfe0(param_1,plVar11,DAT_23eed8d38);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar15 == (longlong *)0x0) goto LAB_23e77a9f8;
        iVar9 = FUN_23a35f020(plVar15);
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        if (iVar9 == -1) goto LAB_23e77a9f8;
        pcVar13 = _Py_FalseStruct_exref;
        if (iVar9 == 0) {
          pcVar13 = _Py_TrueStruct_exref;
        }
        *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
      }
      iVar9 = FUN_23a35f020(pcVar13);
      *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
      if (*(longlong *)pcVar13 == 0) {
        (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
      }
      if (iVar9 == -1) goto LAB_23e77a9f8;
      if (iVar9 == 0) {
LAB_23e77ab20:
        lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar11 = *(longlong **)(lVar10 + 0x28);
        plVar6 = (longlong *)plVar11[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
        *(undefined4 *)(plVar11 + 8) = 0xffffffff;
        if (plVar6 != (longlong *)0x0) {
          plVar11[2] = 0;
          *plVar6 = *plVar6 + -1;
          if (*plVar6 == 0) {
            (**(code **)(plVar6[1] + 0x30))();
          }
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        plVar11[0xf] = 0;
        pcVar13 = _Py_NoneStruct_exref;
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar1 = *plVar1 + -1;
        if (*plVar1 == 0) {
          (**(code **)(plVar1[1] + 0x30))(plVar1);
        }
        *plVar2 = *plVar2 + -1;
        if (*plVar2 != 0) {
          return pcVar13;
        }
        (**(code **)(plVar2[1] + 0x30))(plVar2);
        return pcVar13;
      }
      lVar14 = FUN_23e8e0ba0();
      lVar10 = DAT_23eed8e78;
      if (lVar14 == 0) goto LAB_23e77a9d0;
      *(undefined4 *)(plVar6 + 5) = 0x636;
      plVar11 = (longlong *)
                FUN_23e915840(param_1,lVar14,DAT_23eed8d40,*(undefined8 *)(lVar10 + 0x18));
      if (plVar11 == (longlong *)0x0) goto LAB_23e77abc0;
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      lVar10 = *(longlong *)(param_1 + 0x10);
      if (((*(int *)(*(longlong *)(lVar10 + 0x28) + 0x160) != 0) || (*(int *)(lVar10 + 0x78) != 0))
         && ((iVar9 = Py_MakePendingCalls(), iVar9 < 0 &&
             (pcVar13 = *(code **)(param_1 + 0x60), pcVar13 != (code *)0x0)))) goto LAB_23e77a5af;
      if (*(int *)(lVar10 + 0x68) == 0) {
        plVar11 = *(longlong **)(param_1 + 0x90);
        if (plVar11 != (longlong *)0x0) break;
        goto LAB_23e77a40f;
      }
      PyEval_SaveThread();
      PyEval_AcquireThread(param_1);
      plVar11 = *(longlong **)(param_1 + 0x90);
    } while (plVar11 == (longlong *)0x0);
  }
LAB_23e77a53f:
  plVar15 = *(longlong **)(param_1 + 0x60);
  plVar3 = *(longlong **)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x90) = 0;
  plVar4 = *(longlong **)(param_1 + 0x70);
  *(longlong **)(param_1 + 0x60) = plVar11;
  *plVar11 = *plVar11 + 1;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))();
  }
  if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  pcVar13 = *(code **)(param_1 + 0x60);
LAB_23e77a5af:
  local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
  goto LAB_23e77a5c0;
LAB_23e77a8c8:
  uVar16 = 0x635;
  FUN_23e915740(param_1,local_78,DAT_23eed8c70);
  plVar11 = local_68[0];
  plVar15 = DAT_23ed6a4f8;
  goto joined_r0x00023e77a5e7;
LAB_23e77a9f8:
  pcVar13 = *(code **)(param_1 + 0x60);
  local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
LAB_23e77a5c0:
  plVar11 = *(longlong **)(param_1 + 0x70);
  uVar16 = 0x635;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  local_78._0_8_ = pcVar13;
  plVar15 = DAT_23ed6a4f8;
  goto joined_r0x00023e77a5e7;
LAB_23e77a9d0:
  uVar16 = 0x636;
  FUN_23e915740(param_1,local_78,DAT_23eed8c70);
  plVar11 = local_68[0];
  plVar15 = DAT_23ed6a4f8;
  goto joined_r0x00023e77a5e7;
LAB_23e77abc0:
  local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
  local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
  plVar11 = *(longlong **)(param_1 + 0x70);
  uVar16 = 0x636;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar15 = DAT_23ed6a4f8;
  goto joined_r0x00023e77a5e7;
LAB_23e77aad0:
  local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
  local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
  local_68[0] = *(longlong **)(param_1 + 0x70);
  uVar16 = 0x635;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
  plVar11 = local_68[0];
  plVar15 = DAT_23ed6a4f8;
  if (*(longlong *)pcVar13 == 0) {
    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
    plVar11 = local_68[0];
    plVar15 = DAT_23ed6a4f8;
  }
joined_r0x00023e77a5e7:
  DAT_23ed6a4f8 = plVar15;
  local_68[0] = plVar11;
  if (plVar11 == (longlong *)0x0) {
    if (plVar15 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar15;
      *plVar15 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar13 = _PyRuntime_exref;
    plVar15[2] = 0;
    plVar15[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar10 = *(longlong *)(pcVar13 + 0x1f8);
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(lVar10 + 0x10);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar16;
    lVar10 = *(longlong *)(lVar10 + 0x2e8);
    lVar14 = plVar15[-1];
    puVar5 = *(undefined8 **)(lVar10 + 8);
    *puVar5 = plVar15 + -2;
    plVar15[-2] = lVar10;
    plVar15[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar10 + 8) = plVar15 + -2;
    plVar11 = plVar15;
    if ((local_68[0] != (longlong *)0x0) && (*local_68[0] = *local_68[0] + -1, *local_68[0] == 0)) {
      (**(code **)(local_68[0][1] + 0x30))(local_68[0]);
    }
  }
  else if ((longlong *)plVar11[3] != plVar6) {
    if (plVar15 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar15;
      *plVar15 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar13 = _PyRuntime_exref;
    plVar15[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar10 = *(longlong *)(pcVar13 + 0x1f8);
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar16;
    lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
    lVar14 = plVar15[-1];
    puVar5 = *(undefined8 **)(lVar10 + 8);
    *puVar5 = plVar15 + -2;
    plVar15[-2] = lVar10;
    plVar15[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar10 + 8) = plVar15 + -2;
    plVar15[2] = (longlong)plVar11;
    *plVar11 = *plVar11 + 1;
    plVar11 = plVar15;
    if ((local_68[0] != (longlong *)0x0) && (*local_68[0] = *local_68[0] + -1, *local_68[0] == 0)) {
      (**(code **)(local_68[0][1] + 0x30))(local_68[0]);
    }
  }
  local_68[0] = plVar11;
  FUN_23e8bba40(plVar6,&DAT_23ec5dead,plVar1,plVar2,plVar12);
  if (DAT_23eedad38 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    DAT_23eedad38 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar10 + 0x28);
  plVar6 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar6 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar6 = local_68[0];
  uVar8 = local_78._8_8_;
  uVar7 = local_78._0_8_;
  plVar11[0xf] = 0;
  local_78 = (undefined1  [16])0x0;
  local_68[0] = (longlong *)0x0;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  local_78 = CONCAT88(uVar8,uVar7);
  *plVar1 = *plVar1 + -1;
  local_68[0] = plVar6;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_78._0_8_,local_78._8_8_,local_68[0]);
  return (code *)0x0;
}
