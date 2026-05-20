/* ===== 23aaaaad0 __main__:223 ===== */
/* ghidra_name=FUN_23aaaaad0 entry=23aaaaad0 size=3462 */

code * FUN_23aaaaad0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  undefined4 uVar15;
  longlong *plVar16;
  longlong **local_90;
  undefined8 local_88;
  longlong *local_78;
  undefined8 uStack_70;
  longlong *local_68;
  
  plVar11 = DAT_23ed90c68;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (DAT_23ed90c68 == (longlong *)0x0) {
LAB_23aaaab16:
    DAT_23ed90c68 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ed90c60,DAT_23ed90d18,0x20);
  }
  else {
    lVar9 = *DAT_23ed90c68;
    if (1 < lVar9) {
      *DAT_23ed90c68 = lVar9 + -1;
      goto LAB_23aaaab16;
    }
    if (DAT_23ed90c68[2] != 0) {
      *DAT_23ed90c68 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23aaaab16;
    }
  }
  plVar4 = DAT_23ed90c68;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar11 = DAT_23ed90c68 + 9;
  lVar14 = *(longlong *)(lVar9 + 8);
  DAT_23ed90c68[0xf] = lVar14;
  *(longlong **)(lVar9 + 8) = plVar11;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar4[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  lVar9 = FUN_23ebc0cf0();
  if (lVar9 == 0) {
    plVar16 = (longlong *)0x0;
    FUN_23e915740(param_1,&local_78,DAT_23ed8fba8);
    uVar15 = 0xe6;
    local_90 = (longlong **)local_78;
    local_88 = uStack_70;
    plVar10 = (longlong *)0x0;
    plVar11 = local_68;
    goto LAB_23aaab0d0;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23ed8fbe0);
  plVar11 = DAT_23ed8fe60;
  if (plVar10 == (longlong *)0x0) {
    local_90 = *(longlong ***)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar16 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0xe6;
    local_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23aaab0d0;
  }
  lVar9 = *(longlong *)(param_1 + 0x10);
  plVar12 = *(longlong **)(lVar9 + 0xe20);
  if (plVar12 == (longlong *)0x0) {
    plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
  }
  else {
    lVar14 = plVar12[3];
    *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
    *(longlong *)(lVar9 + 0xe20) = lVar14;
    *plVar12 = 1;
  }
  pcVar6 = _PyRuntime_exref;
  plVar16 = (longlong *)&DAT_23ed6a4c0;
  plVar12[4] = 0;
  lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
  lVar14 = plVar12[-1];
  puVar3 = *(undefined8 **)(lVar9 + 8);
  *puVar3 = plVar12 + -2;
  plVar12[-2] = lVar9;
  plVar12[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar9 + 8) = plVar12 + -2;
  plVar13 = DAT_23ed6a4c0;
  *plVar11 = *plVar11 + 1;
  plVar12[3] = (longlong)plVar11;
  uVar5 = DAT_23ed6cd28;
  if (plVar13 == (longlong *)0x0) {
    plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + 1;
      DAT_23ed6a4c0 = plVar13;
      goto LAB_23aaaac72;
    }
    PyErr_PrintEx(0,0);
    Py_Exit(1);
LAB_23aaab640:
    plVar12 = (longlong *)FUN_23e8bc2f0(plVar16,DAT_23ed8fe78);
    if (plVar12 == (longlong *)0x0) {
LAB_23aaab77c:
      local_90 = *(longlong ***)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      uVar15 = 0xec;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23aaab0d0;
    }
    iVar8 = FUN_23a35f020(plVar12);
    lVar9 = *plVar12 + -1;
    if (iVar8 == -1) {
      local_90 = *(longlong ***)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar12 = lVar9;
      if (lVar9 == 0) {
        FUN_23a334bc0();
      }
      uVar15 = 0xec;
      goto LAB_23aaab0d0;
    }
    *plVar12 = lVar9;
    if (lVar9 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
    if (iVar8 == 1) {
      lVar14 = FUN_23ebc0cf0();
      lVar9 = DAT_23ed8fe80;
      if (lVar14 == 0) {
        FUN_23e915740(param_1,local_90,DAT_23ed8fba8);
        uVar15 = 0xed;
        local_90 = (longlong **)local_78;
        local_88 = uStack_70;
        plVar11 = local_68;
        goto LAB_23aaab0d0;
      }
      *(undefined4 *)(plVar4 + 5) = 0xed;
      plVar11 = (longlong *)
                FUN_23e915840(param_1,lVar14,DAT_23ed8fbb0,*(undefined8 *)(lVar9 + 0x18));
      if (plVar11 == (longlong *)0x0) {
        local_90 = *(longlong ***)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar15 = 0xed;
        local_88 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23aaab0d0;
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      *(undefined4 *)(plVar4 + 5) = 0xee;
      plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar16,DAT_23ed8fe88);
      if (plVar11 == (longlong *)0x0) {
        local_90 = *(longlong ***)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x70);
        uVar15 = 0xee;
        local_88 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        goto LAB_23aaab0d0;
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
LAB_23aaab020:
    iVar8 = FUN_23e8be270(param_1,plVar10,DAT_23ed8fe90);
    if (iVar8 == -1) {
      local_90 = *(longlong ***)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      uVar15 = 0xf0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23aaab0d0;
    }
    if ((iVar8 != 0) &&
       (cVar7 = FUN_23e8d9ac0(plVar10,DAT_23ed8fe90,_Py_FalseStruct_exref), cVar7 == '\0')) {
      local_90 = *(longlong ***)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      uVar15 = 0xf1;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23aaab0d0;
    }
LAB_23aaaad65:
    *(undefined4 *)(plVar4 + 5) = 0xf4;
    plVar11 = (longlong *)FUN_23e915840(param_1,plVar1,DAT_23ed8fe98,plVar2);
    if (plVar11 == (longlong *)0x0) {
      local_90 = *(longlong ***)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      uVar15 = 0xf4;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ed8fd68);
      if (plVar11 != (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed8fd70);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar12 != (longlong *)0x0) {
          *(undefined4 *)(plVar4 + 5) = 0xf7;
          plVar11 = (longlong *)FUN_23e915840(param_1,plVar12,DAT_23ed8fea0,plVar2);
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          if (plVar11 != (longlong *)0x0) {
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar11 = *(longlong **)(lVar9 + 0x28);
            plVar4 = (longlong *)plVar11[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
            *(undefined4 *)(plVar11 + 8) = 0xffffffff;
            if (plVar4 != (longlong *)0x0) {
              plVar11[2] = 0;
              *plVar4 = *plVar4 + -1;
              if (*plVar4 == 0) {
                (**(code **)(plVar4[1] + 0x30))();
              }
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            plVar11[0xf] = 0;
            pcVar6 = _Py_NoneStruct_exref;
            *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
            if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            *plVar1 = *plVar1 + -1;
            if (*plVar1 == 0) {
              (**(code **)(plVar1[1] + 0x30))(plVar1);
            }
            *plVar2 = *plVar2 + -1;
            if (*plVar2 != 0) {
              return pcVar6;
            }
            (**(code **)(plVar2[1] + 0x30))(plVar2);
            return pcVar6;
          }
        }
      }
      local_90 = *(longlong ***)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      uVar15 = 0xf7;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
  }
  else {
LAB_23aaaac72:
    local_90 = &local_78;
    uStack_70 = uVar5;
    local_78 = plVar2;
    lVar9 = FUN_23e94ed00(param_1,plVar13,local_90);
    if (lVar9 == 0) {
      local_90 = *(longlong ***)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
    else {
      plVar12[4] = lVar9;
      plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (plVar11 != (longlong *)0x0) {
        *(undefined4 *)(plVar4 + 5) = 0xe6;
        plVar16 = (longlong *)FUN_23e914090(param_1,plVar10,plVar11);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar16 == (longlong *)0x0) {
          local_90 = *(longlong ***)(param_1 + 0x60);
          plVar11 = *(longlong **)(param_1 + 0x70);
          plVar16 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar15 = 0xe6;
          local_88 = *(undefined8 *)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar10 = (longlong *)0x0;
          goto LAB_23aaab0d0;
        }
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ed8fd88);
        if (plVar10 == (longlong *)0x0) {
LAB_23aaab450:
          local_90 = *(longlong ***)(param_1 + 0x60);
          plVar11 = *(longlong **)(param_1 + 0x70);
          plVar16 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar15 = 0xe9;
          local_88 = *(undefined8 *)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar10 = (longlong *)0x0;
          goto LAB_23aaab0d0;
        }
        iVar8 = FUN_23a35f020(plVar10);
        lVar9 = *plVar10 + -1;
        if (iVar8 == -1) {
          local_90 = *(longlong ***)(param_1 + 0x60);
          plVar11 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_88 = *(undefined8 *)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar10 = lVar9;
          if (lVar9 == 0) {
            plVar16 = (longlong *)0x0;
            (**(code **)(plVar10[1] + 0x30))(plVar10);
            uVar15 = 0xe9;
            plVar10 = (longlong *)0x0;
          }
          else {
            uVar15 = 0xe9;
            plVar16 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
          }
          goto LAB_23aaab0d0;
        }
        *plVar10 = lVar9;
        if (lVar9 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (iVar8 != 0) {
          plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ed8fd88);
          if (plVar11 == (longlong *)0x0) goto LAB_23aaab450;
          iVar8 = FUN_23e8be270(param_1,plVar11,DAT_23ed8fe68);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (iVar8 == -1) {
            local_90 = *(longlong ***)(param_1 + 0x60);
            plVar11 = *(longlong **)(param_1 + 0x70);
            plVar16 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar15 = 0xe9;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar10 = (longlong *)0x0;
            goto LAB_23aaab0d0;
          }
          if (iVar8 != 0) {
            plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ed8fd88);
            if (plVar11 == (longlong *)0x0) {
              local_90 = *(longlong ***)(param_1 + 0x60);
              plVar11 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar15 = 0xea;
              local_88 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar16 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              goto LAB_23aaab0d0;
            }
            plVar10 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed8fe68);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (plVar10 == (longlong *)0x0) {
              local_90 = *(longlong ***)(param_1 + 0x60);
              plVar11 = *(longlong **)(param_1 + 0x70);
              plVar16 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar15 = 0xea;
              local_88 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23aaab0d0;
            }
            plVar16 = (longlong *)FUN_23e8bbbe0(param_1,plVar10,DAT_23ed8fe70,_Py_NoneStruct_exref);
            if (plVar16 == (longlong *)0x0) {
              local_90 = *(longlong ***)(param_1 + 0x60);
              plVar11 = *(longlong **)(param_1 + 0x70);
              uVar15 = 0xeb;
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_88 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23aaab0d0;
            }
            iVar8 = FUN_23a35f020(plVar16);
            if (iVar8 != -1) {
              if (iVar8 != 0) goto LAB_23aaab640;
              goto LAB_23aaab020;
            }
            goto LAB_23aaab77c;
          }
        }
        plVar16 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        goto LAB_23aaaad65;
      }
      local_90 = *(longlong ***)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = *plVar10 + -1;
      plVar16 = (longlong *)0x0;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        uVar15 = 0xe6;
        plVar10 = (longlong *)0x0;
        goto LAB_23aaab0d0;
      }
    }
    plVar16 = (longlong *)0x0;
    uVar15 = 0xe6;
    plVar10 = (longlong *)0x0;
  }
LAB_23aaab0d0:
  plVar12 = DAT_23ed6a4f8;
  if (plVar11 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar11 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar11;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar9 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar15;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar14 = plVar12[-1];
    puVar3 = *(undefined8 **)(lVar9 + 8);
    *puVar3 = plVar12 + -2;
    plVar12[-2] = lVar9;
    plVar12[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar9 + 8) = plVar12 + -2;
    plVar13 = plVar12;
  }
  else {
    plVar13 = plVar11;
    if ((longlong *)plVar11[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar13 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar13;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar12[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar15;
      pcVar6 = _PyRuntime_exref;
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
      lVar14 = plVar12[-1];
      puVar3 = *(undefined8 **)(lVar9 + 8);
      *puVar3 = plVar12 + -2;
      plVar12[-2] = lVar9;
      plVar12[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
      lVar14 = *plVar11;
      *(longlong **)(lVar9 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plVar11;
      plVar13 = plVar12;
      if (lVar14 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec31985,plVar1,plVar2,plVar10,plVar16);
  if (DAT_23ed90c68 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23ed90c68 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar9 + 0x28);
  plVar4 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar11[0xf] = 0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_90,local_88,plVar13);
  return (code *)0x0;
}
