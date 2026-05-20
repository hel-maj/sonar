/* ===== 23e83a540 workers.fishing.trigger_monitor:190 ===== */
/* ghidra_name=FUN_23e83a540 entry=23e83a540 size=3493 */

code * FUN_23e83a540(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  code *pcVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  code *pcVar12;
  longlong *plVar13;
  code *pcVar14;
  longlong *plVar15;
  undefined8 uVar16;
  longlong *plVar17;
  undefined4 uVar18;
  longlong *local_78;
  longlong *plStack_70;
  longlong *local_68;
  undefined4 uVar19;
  
  plVar9 = DAT_23eede4b0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (DAT_23eede4b0 == (longlong *)0x0) {
LAB_23e83a586:
    DAT_23eede4b0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede4a8,DAT_23eede5a0,0x20);
  }
  else {
    lVar11 = *DAT_23eede4b0;
    if (1 < lVar11) {
      *DAT_23eede4b0 = lVar11 + -1;
      goto LAB_23e83a586;
    }
    if (DAT_23eede4b0[2] != 0) {
      *DAT_23eede4b0 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e83a586;
    }
  }
  plVar4 = DAT_23eede4b0;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar9 = DAT_23eede4b0 + 9;
  lVar3 = *(longlong *)(lVar11 + 8);
  DAT_23eede4b0[0xf] = lVar3;
  *(longlong **)(lVar11 + 8) = plVar9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar16 = DAT_23eedc050;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar16);
  if (plVar9 == (longlong *)0x0) {
    plVar9 = *(longlong **)(param_1 + 0x60);
    plVar17 = *(longlong **)(param_1 + 0x70);
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar19 = 0xc0;
    plVar6 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar14 = (code *)0x0;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e83abe0;
  }
  plVar10 = (longlong *)FUN_23e8c6f80(plVar9,plVar2);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (plVar10 == (longlong *)0x0) {
    plVar9 = *(longlong **)(param_1 + 0x60);
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar14 = (code *)0x0;
    plVar13 = DAT_23ed6a4f8;
    plVar6 = *(longlong **)(param_1 + 0x68);
    uVar19 = 0xc0;
    goto joined_r0x00023e83abe0;
  }
  *(undefined4 *)(plVar4 + 5) = 0xc2;
  plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23ed6cee0);
  if (plVar9 == (longlong *)0x0) {
    plVar9 = *(longlong **)(param_1 + 0x60);
    plVar17 = *(longlong **)(param_1 + 0x70);
    uVar19 = 0xc2;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar6 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar14 = (code *)0x0;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e83abe0;
  }
  iVar8 = FUN_23a35f020(plVar9);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (iVar8 == -1) {
    plVar9 = *(longlong **)(param_1 + 0x60);
    plVar17 = *(longlong **)(param_1 + 0x70);
    pcVar14 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar19 = 0xc2;
    plVar6 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e83abe0;
  }
  if (iVar8 == 0) {
    uVar16 = FUN_23a3a0d40(DAT_23ed6cf28);
    plVar9 = DAT_23eedc210;
    lVar11 = *(longlong *)(param_1 + 0x10);
    pcVar12 = *(code **)(lVar11 + 0xe20);
    if (pcVar12 == (code *)0x0) {
      pcVar12 = (code *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar3 = *(longlong *)(pcVar12 + 0x18);
      *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
      *(longlong *)(lVar11 + 0xe20) = lVar3;
      *(longlong *)pcVar12 = 1;
    }
    pcVar14 = _PyRuntime_exref;
    *(longlong *)(pcVar12 + 0x20) = 0;
    lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar14 + 0x1f8) + 0x10) + 0x2e8);
    lVar3 = *(longlong *)(pcVar12 + -8);
    puVar5 = *(undefined8 **)(lVar11 + 8);
    *puVar5 = pcVar12 + -0x10;
    *(longlong *)(pcVar12 + -0x10) = lVar11;
    *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(code **)(lVar11 + 8) = pcVar12 + -0x10;
    *plVar9 = *plVar9 + 1;
    *(longlong **)(pcVar12 + 0x18) = plVar9;
    plVar9 = DAT_23ed6cd28;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar17 == (longlong *)0x0) {
LAB_23e83b2c1:
        PyErr_PrintEx(0);
        Py_Exit(1);
        goto LAB_23e83b2d4;
      }
      *plVar17 = *plVar17 + 1;
      DAT_23ed6a4c0 = plVar17;
    }
    plStack_70 = plVar9;
    local_78 = plVar10;
    lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
    if (lVar11 != 0) {
      *(longlong *)(pcVar12 + 0x20) = lVar11;
      plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcVar12);
      *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
      if (*(longlong *)pcVar12 == 0) {
        (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
      }
      if (plVar9 != (longlong *)0x0) {
        *(undefined4 *)(plVar4 + 5) = 0xc3;
        plVar17 = (longlong *)FUN_23e914090(param_1,uVar16,plVar9);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar17 == (longlong *)0x0) {
          plVar9 = *(longlong **)(param_1 + 0x60);
          plVar17 = *(longlong **)(param_1 + 0x70);
          pcVar14 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar19 = 0xc3;
          plVar6 = *(longlong **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e83abe0;
        }
        *plVar17 = *plVar17 + -1;
        if (*plVar17 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
        pcVar14 = _Py_NoneStruct_exref;
        lVar11 = *(longlong *)(param_1 + 0x38);
        lVar3 = *(longlong *)(lVar11 + 8);
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        plVar9 = *(longlong **)(lVar3 + 0x28);
        plVar4 = (longlong *)plVar9[2];
        *(undefined8 *)(lVar11 + 8) = *(undefined8 *)(lVar3 + 0x30);
        *(undefined4 *)(plVar9 + 8) = 0xffffffff;
        if (plVar4 != (longlong *)0x0) {
          plVar9[2] = 0;
          *plVar4 = *plVar4 + -1;
          if (*plVar4 == 0) {
            (**(code **)(plVar4[1] + 0x30))();
          }
        }
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        plVar9[0xf] = 0;
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        goto LAB_23e83ab3a;
      }
      plVar9 = *(longlong **)(param_1 + 0x60);
      plVar17 = *(longlong **)(param_1 + 0x70);
      uVar19 = 0xc3;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar6 = *(longlong **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar14 = (code *)0x0;
      plVar13 = DAT_23ed6a4f8;
      goto joined_r0x00023e83abe0;
    }
    plVar9 = *(longlong **)(param_1 + 0x60);
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar19 = 0xc3;
    uVar18 = 0xc3;
    plVar6 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
    lVar11 = *(longlong *)pcVar12;
  }
  else {
    lVar11 = FUN_23e8db510();
    if (lVar11 == 0) {
      FUN_23e915740(param_1,&local_78,DAT_23eedc000);
      uVar19 = 0xc6;
      pcVar14 = (code *)0x0;
      plVar17 = local_68;
      plVar13 = DAT_23ed6a4f8;
      plVar9 = local_78;
      plVar6 = plStack_70;
      goto joined_r0x00023e83abe0;
    }
    pcVar12 = (code *)FUN_23e8bc2f0(lVar11,DAT_23eedc218);
    if (pcVar12 == (code *)0x0) {
LAB_23e83aee0:
      plVar9 = *(longlong **)(param_1 + 0x60);
      plVar17 = *(longlong **)(param_1 + 0x70);
      pcVar14 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar13 = DAT_23ed6a4f8;
      plVar6 = *(longlong **)(param_1 + 0x68);
      uVar19 = 0xc6;
      goto joined_r0x00023e83abe0;
    }
    plVar13 = (longlong *)FUN_23e8bd350(plVar10);
    if (plVar13 != (longlong *)0x0) {
      lVar11 = FUN_23e8db510();
      if (lVar11 == 0) {
        FUN_23e915740(param_1,&local_78,DAT_23eedc000);
        *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
        lVar11 = *(longlong *)pcVar12;
        plVar9 = local_78;
        plVar6 = plStack_70;
        plVar17 = local_68;
      }
      else {
        plVar9 = (longlong *)FUN_23e8bc2f0(lVar11,DAT_23eedc220);
        if (plVar9 != (longlong *)0x0) {
          *(undefined4 *)(plVar4 + 5) = 0xc6;
          local_78 = plVar13;
          plStack_70 = plVar9;
          pcVar14 = (code *)FUN_23e94ed00(param_1,pcVar12,&local_78);
          *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
          if (*(longlong *)pcVar12 == 0) {
            (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
          }
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          pcVar12 = _Py_NoneStruct_exref;
          if (pcVar14 == (code *)0x0) goto LAB_23e83aee0;
          if (pcVar14 != _Py_NoneStruct_exref) {
LAB_23e83a7b0:
            lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar9 = *(longlong **)(lVar11 + 0x28);
            plVar4 = (longlong *)plVar9[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
            *(undefined4 *)(plVar9 + 8) = 0xffffffff;
            if (plVar4 != (longlong *)0x0) {
              plVar9[2] = 0;
              *plVar4 = *plVar4 + -1;
              if (*plVar4 == 0) {
                (**(code **)(plVar4[1] + 0x30))();
              }
            }
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            plVar9[0xf] = 0;
            *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
            if (*(longlong *)pcVar14 == 0) {
              (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
            }
LAB_23e83ab3a:
            *plVar1 = *plVar1 + -1;
            if (*plVar1 == 0) {
              (**(code **)(plVar1[1] + 0x30))(plVar1);
            }
            *plVar2 = *plVar2 + -1;
            if (*plVar2 != 0) {
              return pcVar14;
            }
            (**(code **)(plVar2[1] + 0x30))(plVar2);
            return pcVar14;
          }
          uVar16 = FUN_23a3a0d40(DAT_23ed6cf28);
          plVar9 = DAT_23eedc228;
          lVar11 = *(longlong *)(param_1 + 0x10);
          plVar13 = *(longlong **)(lVar11 + 0xe20);
          if (plVar13 == (longlong *)0x0) {
            plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar3 = plVar13[3];
            *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
            *(longlong *)(lVar11 + 0xe20) = lVar3;
            *plVar13 = 1;
          }
          pcVar7 = _PyRuntime_exref;
          plVar13[4] = 0;
          lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar7 + 0x1f8) + 0x10) + 0x2e8);
          lVar3 = plVar13[-1];
          puVar5 = *(undefined8 **)(lVar11 + 8);
          *puVar5 = plVar13 + -2;
          plVar13[-2] = lVar11;
          plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
          *(longlong **)(lVar11 + 8) = plVar13 + -2;
          plVar17 = DAT_23ed6a4c0;
          *plVar9 = *plVar9 + 1;
          plVar13[3] = (longlong)plVar9;
          plVar9 = DAT_23ed6cd28;
          if (plVar17 == (longlong *)0x0) {
            plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar17 == (longlong *)0x0) goto LAB_23e83b2c1;
            *plVar17 = *plVar17 + 1;
            DAT_23ed6a4c0 = plVar17;
          }
          plStack_70 = plVar9;
          local_78 = plVar10;
          lVar11 = FUN_23e94ed00(param_1,plVar17,&local_78);
          if (lVar11 == 0) {
            plVar9 = *(longlong **)(param_1 + 0x60);
            plVar17 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar6 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar13 = *plVar13 + -1;
            pcVar14 = pcVar12;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
              plVar13 = DAT_23ed6a4f8;
              uVar19 = 200;
            }
            else {
              plVar13 = DAT_23ed6a4f8;
              uVar19 = 200;
            }
            goto joined_r0x00023e83abe0;
          }
          plVar13[4] = lVar11;
          plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (plVar9 != (longlong *)0x0) {
            *(undefined4 *)(plVar4 + 5) = 200;
            plVar17 = (longlong *)FUN_23e914090(param_1,uVar16,plVar9);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (plVar17 != (longlong *)0x0) {
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              goto LAB_23e83a7b0;
            }
          }
LAB_23e83b2d4:
          plVar9 = *(longlong **)(param_1 + 0x60);
          plVar17 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar14 = pcVar12;
          plVar13 = DAT_23ed6a4f8;
          plVar6 = *(longlong **)(param_1 + 0x68);
          uVar19 = 200;
          goto joined_r0x00023e83abe0;
        }
        plVar9 = *(longlong **)(param_1 + 0x60);
        plVar17 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar6 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
        lVar11 = *(longlong *)pcVar12;
      }
      if (lVar11 == 0) {
        (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        pcVar14 = (code *)0x0;
        (**(code **)(plVar13[1] + 0x30))(plVar13);
        plVar13 = DAT_23ed6a4f8;
        uVar19 = 0xc6;
      }
      else {
        pcVar14 = (code *)0x0;
        plVar13 = DAT_23ed6a4f8;
        uVar19 = 0xc6;
      }
      goto joined_r0x00023e83abe0;
    }
    plVar9 = *(longlong **)(param_1 + 0x60);
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar19 = 0xc6;
    uVar18 = 0xc6;
    plVar6 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
    lVar11 = *(longlong *)pcVar12;
  }
  pcVar14 = (code *)0x0;
  plVar13 = DAT_23ed6a4f8;
  if (lVar11 == 0) {
    pcVar14 = (code *)0x0;
    (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
    plVar13 = DAT_23ed6a4f8;
    uVar19 = uVar18;
  }
joined_r0x00023e83abe0:
  DAT_23ed6a4f8 = plVar13;
  if (plVar17 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar15 = plVar13;
    }
    pcVar12 = _PyRuntime_exref;
    plVar15[3] = (longlong)plVar4;
    plVar15[2] = 0;
    *plVar4 = *plVar4 + 1;
    lVar11 = *(longlong *)(pcVar12 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar19;
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar3 = plVar15[-1];
    puVar5 = *(undefined8 **)(lVar11 + 8);
    *puVar5 = plVar15 + -2;
    plVar15[-2] = lVar11;
    plVar15[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar11 + 8) = plVar15 + -2;
  }
  else {
    plVar15 = plVar17;
    if ((longlong *)plVar17[3] != plVar4) {
      if (plVar13 == (longlong *)0x0) {
        plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar13;
        *plVar13 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar15 = plVar13;
      }
      pcVar12 = _PyRuntime_exref;
      plVar15[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar11 = *(longlong *)(pcVar12 + 0x1f8);
      *(undefined4 *)((longlong)plVar15 + 0x24) = uVar19;
      *(undefined4 *)(plVar15 + 4) = 0xffffffff;
      lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
      lVar3 = plVar15[-1];
      puVar5 = *(undefined8 **)(lVar11 + 8);
      *puVar5 = plVar15 + -2;
      plVar15[-2] = lVar11;
      plVar15[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar17;
      *(longlong **)(lVar11 + 8) = plVar15 + -2;
      plVar15[2] = (longlong)plVar17;
      if (lVar3 == 0) {
        (**(code **)(plVar17[1] + 0x30))(plVar17);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5e2ee,plVar1,plVar2,plVar10,pcVar14);
  if (DAT_23eede4b0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23eede4b0 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar11 + 0x28);
  plVar17 = (longlong *)plVar4[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar4 + 8) = 0xffffffff;
  if (plVar17 != (longlong *)0x0) {
    plVar4[2] = 0;
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))();
    }
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  plVar4[0xf] = 0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((pcVar14 != (code *)0x0) &&
     (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
    (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,plVar9,plVar6,plVar15);
  return (code *)0x0;
}
