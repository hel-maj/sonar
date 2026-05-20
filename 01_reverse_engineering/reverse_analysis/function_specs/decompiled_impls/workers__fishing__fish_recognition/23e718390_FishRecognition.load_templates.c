/* ===== 23e718390 workers.fishing.fish_recognition:238 ===== */
/* ghidra_name=FUN_23e718390 entry=23e718390 size=4470 */

longlong * FUN_23e718390(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  code *pcVar9;
  undefined8 uVar10;
  longlong *plVar11;
  code *pcVar12;
  longlong lVar13;
  longlong *plVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  code *unaff_R15;
  undefined8 uVar17;
  code *local_b0;
  code *local_88;
  undefined8 uStack_80;
  undefined1 local_78 [16];
  longlong *local_68;
  
  plVar8 = DAT_23eedb068;
  plVar1 = (longlong *)*param_3;
  local_68 = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  if (DAT_23eedb068 == (longlong *)0x0) {
LAB_23e7183ea:
    DAT_23eedb068 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedb060,DAT_23eedb148,0x20);
  }
  else {
    lVar13 = *DAT_23eedb068;
    if (1 < lVar13) {
      *DAT_23eedb068 = lVar13 + -1;
      goto LAB_23e7183ea;
    }
    if (DAT_23eedb068[2] != 0) {
      *DAT_23eedb068 = lVar13 + -1;
      if (lVar13 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e7183ea;
    }
  }
  plVar4 = DAT_23eedb068;
  lVar13 = *(longlong *)(param_1 + 0x38);
  plVar8 = DAT_23eedb068 + 9;
  lVar2 = *(longlong *)(lVar13 + 8);
  DAT_23eedb068[0xf] = lVar2;
  *(longlong **)(lVar13 + 8) = plVar8;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed6cf28);
  if ((plVar8 == (longlong *)0x0) || (lVar13 = *plVar8, lVar13 == 0)) goto LAB_23e718e30;
  *(undefined4 *)(plVar4 + 5) = 0xf3;
  plVar8 = (longlong *)FUN_23e94bb80(param_1,lVar13,DAT_23eeda078);
  if (plVar8 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    pcVar12 = (code *)0x0;
    unaff_R15 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0xf3;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar9 = (code *)0x0;
    goto LAB_23e718c4b;
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed9e98);
  unaff_R15 = (code *)0x0;
  if (plVar8 == (longlong *)0x0) {
LAB_23e718e48:
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    pcVar12 = (code *)0x0;
    pcVar9 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0xf4;
    uVar15 = 0xf4;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_68 != (longlong *)0x0) {
LAB_23e718c54:
      plVar14 = local_68;
      plVar8 = DAT_23ed6a4f8;
      plVar11 = local_68;
      if ((longlong *)local_68[3] != plVar4) {
        if (DAT_23ed6a4f8 == (longlong *)0x0) {
          plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          plVar11 = (longlong *)*DAT_23ed6a4f8;
          *DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = plVar11;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        pcVar5 = _PyRuntime_exref;
        plVar8[3] = (longlong)plVar4;
        *plVar4 = *plVar4 + 1;
        lVar13 = *(longlong *)(pcVar5 + 0x1f8);
        *(undefined4 *)((longlong)plVar8 + 0x24) = uVar15;
        *(undefined4 *)(plVar8 + 4) = 0xffffffff;
        lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
        lVar2 = plVar8[-1];
        puVar3 = *(undefined8 **)(lVar13 + 8);
        *puVar3 = plVar8 + -2;
        plVar8[-2] = lVar13;
        plVar8[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
        lVar2 = *plVar14;
        *(longlong **)(lVar13 + 8) = plVar8 + -2;
        plVar8[2] = (longlong)plVar14;
        plVar11 = plVar8;
        if (lVar2 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
      }
      goto LAB_23e718cff;
    }
    local_68 = (longlong *)0x0;
  }
  else {
    *(undefined4 *)(plVar4 + 5) = 0xf4;
    pcVar9 = (code *)FUN_23e91bfe0(param_1,plVar8,DAT_23eed9e98);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    pcVar12 = _Py_NoneStruct_exref;
    if (pcVar9 == (code *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      pcVar12 = (code *)0x0;
      unaff_R15 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar15 = 0xf4;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else if (pcVar9 == _Py_NoneStruct_exref) {
      uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar4 + 5) = 0xf7;
      plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar10,DAT_23eeda080);
      if (plVar8 != (longlong *)0x0) {
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        plVar8 = DAT_23eeda088;
        lVar13 = *(longlong *)(param_1 + 0x38);
        lVar2 = *(longlong *)(lVar13 + 8);
        *DAT_23eeda088 = *DAT_23eeda088 + 1;
        plVar4 = *(longlong **)(lVar2 + 0x28);
        plVar11 = (longlong *)plVar4[2];
        *(undefined8 *)(lVar13 + 8) = *(undefined8 *)(lVar2 + 0x30);
        *(undefined4 *)(plVar4 + 8) = 0xffffffff;
        if (plVar11 != (longlong *)0x0) {
          plVar4[2] = 0;
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))();
          }
        }
        *plVar4 = *plVar4 + -1;
        if (*plVar4 == 0) {
          (**(code **)(plVar4[1] + 0x30))(plVar4);
        }
        plVar4[0xf] = 0;
        *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
        lVar13 = *(longlong *)pcVar12;
        goto joined_r0x00023e718b4b;
      }
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      pcVar12 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar15 = 0xf7;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      unaff_R15 = (code *)0x0;
    }
    else {
      uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar4 + 5) = 0xfa;
      plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar10,DAT_23eeda090);
      if (plVar8 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        pcVar12 = (code *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar15 = 0xfa;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        unaff_R15 = (code *)0x0;
      }
      else {
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        *(undefined4 *)(plVar4 + 5) = 0xfb;
        plVar8 = (longlong *)FUN_23e915840(param_1,plVar1,DAT_23eeda098,pcVar9);
        if (plVar8 == (longlong *)0x0) {
LAB_23e718f30:
          uVar10 = *(undefined8 *)(param_1 + 0x60);
          uVar17 = *(undefined8 *)(param_1 + 0x68);
          plVar8 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        else {
          plVar11 = (longlong *)FUN_23a388310(plVar8);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if (plVar11 == (longlong *)0x0) goto LAB_23e718f30;
          unaff_R15 = (code *)(**(code **)(plVar11[1] + 0xe0))(plVar11);
          if ((unaff_R15 != (code *)0x0) ||
             (unaff_R15 = (code *)FUN_23a3c1b70(param_1,local_78,0,2), unaff_R15 != (code *)0x0)) {
            pcVar12 = (code *)(**(code **)(plVar11[1] + 0xe0))(plVar11);
            if (((pcVar12 == (code *)0x0) &&
                (pcVar12 = (code *)FUN_23a3c1b70(param_1,local_78,1,2), pcVar12 == (code *)0x0)) ||
               (cVar6 = FUN_23a3884a0(param_1,local_78,plVar11,2), cVar6 == '\0')) {
              *plVar11 = *plVar11 + -1;
              plVar8 = local_68;
              uVar10 = local_78._0_8_;
              uVar17 = local_78._8_8_;
              if (*plVar11 == 0) goto LAB_23e718f92;
LAB_23e718c0d:
              local_68 = (longlong *)0x0;
              local_78 = (undefined1  [16])0x0;
              *(longlong *)unaff_R15 = *(longlong *)unaff_R15 + -1;
              if (*(longlong *)unaff_R15 == 0) {
                (**(code **)(*(longlong *)(unaff_R15 + 8) + 0x30))(unaff_R15);
              }
              goto LAB_23e718c1d;
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (*(longlong *)unaff_R15 == 0) {
              (**(code **)(*(longlong *)(unaff_R15 + 8) + 0x30))(unaff_R15);
            }
            if (*(longlong *)pcVar12 == 0) {
              (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
            }
            iVar7 = FUN_23a35f020(unaff_R15);
            if (iVar7 == -1) {
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar15 = 0xfd;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e718c4b;
            }
            if (iVar7 == 0) {
              uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
              *(undefined4 *)(plVar4 + 5) = 0x101;
              plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar10,DAT_23eeda0b8);
              if (plVar8 == (longlong *)0x0) {
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar15 = 0x101;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e718c4b;
              }
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
              plVar11 = DAT_23eeda0c0;
              lVar13 = *(longlong *)(param_1 + 0x10);
              plVar8 = *(longlong **)(lVar13 + 0xe20);
              if (plVar8 == (longlong *)0x0) {
                plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
              }
              else {
                lVar2 = plVar8[3];
                *(int *)(lVar13 + 0xebc) = *(int *)(lVar13 + 0xebc) + -1;
                *(longlong *)(lVar13 + 0xe20) = lVar2;
                *plVar8 = 1;
              }
              local_b0 = _PyRuntime_exref;
              plVar8[4] = 0;
              uVar17 = DAT_23eeda0b0;
              lVar13 = *(longlong *)(*(longlong *)(*(longlong *)(local_b0 + 0x1f8) + 0x10) + 0x2e8);
              lVar2 = plVar8[-1];
              puVar3 = *(undefined8 **)(lVar13 + 8);
              *puVar3 = plVar8 + -2;
              plVar8[-2] = lVar13;
              plVar8[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
              *(longlong **)(lVar13 + 8) = plVar8 + -2;
              plVar14 = DAT_23ed6a4c0;
              *plVar11 = *plVar11 + 1;
              plVar8[3] = (longlong)plVar11;
              if (plVar14 == (longlong *)0x0) {
                plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar14 == (longlong *)0x0) goto LAB_23e718e30;
                *plVar14 = *plVar14 + 1;
                DAT_23ed6a4c0 = plVar14;
              }
              uStack_80 = uVar17;
              local_88 = pcVar12;
              lVar13 = FUN_23e94ed00(param_1,plVar14,&local_88);
              if (lVar13 != 0) {
                plVar8[4] = lVar13;
                plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar8);
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                if (plVar11 == (longlong *)0x0) {
LAB_23e719181:
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0x102;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e718c4b;
                }
                *(undefined4 *)(plVar4 + 5) = 0x102;
                plVar8 = (longlong *)FUN_23e914090(param_1,uVar10,plVar11);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if (plVar8 == (longlong *)0x0) goto LAB_23e719181;
LAB_23e718937:
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar8 = *(longlong **)(lVar13 + 0x28);
                plVar4 = (longlong *)plVar8[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
                *(undefined4 *)(plVar8 + 8) = 0xffffffff;
                if (plVar4 != (longlong *)0x0) {
                  plVar8[2] = 0;
                  *plVar4 = *plVar4 + -1;
                  if (*plVar4 == 0) {
                    (**(code **)(plVar4[1] + 0x30))();
                  }
                }
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                lVar13 = *(longlong *)(param_1 + 0x10);
                plVar8[0xf] = 0;
                plVar8 = *(longlong **)(lVar13 + 0xe20);
                if (plVar8 == (longlong *)0x0) {
                  plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar2 = plVar8[3];
                  *(int *)(lVar13 + 0xebc) = *(int *)(lVar13 + 0xebc) + -1;
                  *(longlong *)(lVar13 + 0xe20) = lVar2;
                  *plVar8 = 1;
                }
                lVar13 = *(longlong *)
                          (*(longlong *)(*(longlong *)(local_b0 + 0x1f8) + 0x10) + 0x2e8);
                lVar2 = plVar8[-1];
                puVar3 = *(undefined8 **)(lVar13 + 8);
                *puVar3 = plVar8 + -2;
                plVar8[-2] = lVar13;
                plVar8[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
                *(longlong **)(lVar13 + 8) = plVar8 + -2;
                *(longlong *)unaff_R15 = *(longlong *)unaff_R15 + 1;
                plVar8[3] = (longlong)unaff_R15;
                *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
                plVar8[4] = (longlong)pcVar12;
                *(longlong *)pcVar9 = *(longlong *)pcVar9 + -1;
                if (*(longlong *)pcVar9 == 0) {
                  (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
                }
                *(longlong *)unaff_R15 = *(longlong *)unaff_R15 + -1;
                if (*(longlong *)unaff_R15 == 0) {
                  (**(code **)(*(longlong *)(unaff_R15 + 8) + 0x30))(unaff_R15);
                }
                *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
                lVar13 = *(longlong *)pcVar12;
joined_r0x00023e718b4b:
                if (lVar13 == 0) {
                  (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
                }
                *plVar1 = *plVar1 + -1;
                if (*plVar1 != 0) {
                  return plVar8;
                }
                (**(code **)(plVar1[1] + 0x30))(plVar1);
                return plVar8;
              }
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar15 = 0x102;
              uVar16 = 0x102;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar8 = *plVar8 + -1;
              lVar13 = *plVar8;
            }
            else {
              uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
              plVar11 = DAT_23eeda0a0;
              lVar13 = *(longlong *)(param_1 + 0x10);
              plVar8 = *(longlong **)(lVar13 + 0xe20);
              if (plVar8 == (longlong *)0x0) {
                plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
              }
              else {
                lVar2 = plVar8[3];
                *(int *)(lVar13 + 0xebc) = *(int *)(lVar13 + 0xebc) + -1;
                *(longlong *)(lVar13 + 0xe20) = lVar2;
                *plVar8 = 1;
              }
              local_b0 = _PyRuntime_exref;
              plVar8[4] = 0;
              lVar13 = *(longlong *)(*(longlong *)(*(longlong *)(local_b0 + 0x1f8) + 0x10) + 0x2e8);
              lVar2 = plVar8[-1];
              puVar3 = *(undefined8 **)(lVar13 + 8);
              *puVar3 = plVar8 + -2;
              plVar8[-2] = lVar13;
              plVar8[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
              *(longlong **)(lVar13 + 8) = plVar8 + -2;
              plVar14 = DAT_23ed6a4c0;
              *plVar11 = *plVar11 + 1;
              plVar8[3] = (longlong)plVar11;
              uVar17 = DAT_23ed6cd28;
              if (plVar14 == (longlong *)0x0) {
                plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar14 != (longlong *)0x0) {
                  *plVar14 = *plVar14 + 1;
                  DAT_23ed6a4c0 = plVar14;
                  goto LAB_23e718725;
                }
LAB_23e718e30:
                PyErr_PrintEx(0);
                Py_Exit(1);
                goto LAB_23e718e48;
              }
LAB_23e718725:
              uStack_80 = uVar17;
              local_88 = unaff_R15;
              lVar13 = FUN_23e94ed00(param_1,plVar14,&local_88);
              if (lVar13 != 0) {
                plVar8[4] = lVar13;
                plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar8);
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                if (plVar11 != (longlong *)0x0) {
                  *(undefined4 *)(plVar4 + 5) = 0xfe;
                  plVar8 = (longlong *)FUN_23e914090(param_1,uVar10);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar8 != (longlong *)0x0) {
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
                    plVar11 = DAT_23eeda0a8;
                    lVar13 = *(longlong *)(param_1 + 0x10);
                    plVar8 = *(longlong **)(lVar13 + 0xe20);
                    if (plVar8 == (longlong *)0x0) {
                      plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                    }
                    else {
                      lVar2 = plVar8[3];
                      *(int *)(lVar13 + 0xebc) = *(int *)(lVar13 + 0xebc) + -1;
                      *(longlong *)(lVar13 + 0xe20) = lVar2;
                      *plVar8 = 1;
                    }
                    plVar8[4] = 0;
                    uVar17 = DAT_23eeda0b0;
                    lVar13 = *(longlong *)
                              (*(longlong *)(*(longlong *)(local_b0 + 0x1f8) + 0x10) + 0x2e8);
                    lVar2 = plVar8[-1];
                    puVar3 = *(undefined8 **)(lVar13 + 8);
                    *puVar3 = plVar8 + -2;
                    plVar8[-2] = lVar13;
                    plVar8[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
                    *(longlong **)(lVar13 + 8) = plVar8 + -2;
                    plVar14 = DAT_23ed6a4c0;
                    *plVar11 = *plVar11 + 1;
                    plVar8[3] = (longlong)plVar11;
                    if (plVar14 == (longlong *)0x0) {
                      plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                      if (plVar14 == (longlong *)0x0) goto LAB_23e718e30;
                      *plVar14 = *plVar14 + 1;
                      DAT_23ed6a4c0 = plVar14;
                    }
                    uStack_80 = uVar17;
                    local_88 = pcVar12;
                    lVar13 = FUN_23e94ed00(param_1,plVar14,&local_88);
                    if (lVar13 != 0) {
                      plVar8[4] = lVar13;
                      plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar8);
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                      }
                      if (plVar11 != (longlong *)0x0) {
                        *(undefined4 *)(plVar4 + 5) = 0xff;
                        plVar8 = (longlong *)FUN_23e914090(param_1,uVar10,plVar11);
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                        }
                        if (plVar8 != (longlong *)0x0) goto LAB_23e718937;
                      }
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      uVar15 = 0xff;
                      goto LAB_23e718c4b;
                    }
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar15 = 0xff;
                    uVar16 = 0xff;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar8 = *plVar8 + -1;
                    lVar13 = *plVar8;
                    goto joined_r0x00023e7194ea;
                  }
                }
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar15 = 0xfe;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e718c4b;
              }
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar15 = 0xfe;
              uVar16 = 0xfe;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar8 = *plVar8 + -1;
              lVar13 = *plVar8;
            }
joined_r0x00023e7194ea:
            if (lVar13 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
              uVar15 = uVar16;
            }
            goto LAB_23e718c4b;
          }
          pcVar12 = (code *)0x0;
          *plVar11 = *plVar11 + -1;
          plVar8 = local_68;
          uVar10 = local_78._0_8_;
          uVar17 = local_78._8_8_;
          if (*plVar11 == 0) {
LAB_23e718f92:
            plVar8 = local_68;
            (**(code **)(plVar11[1] + 0x30))(plVar11);
            local_68 = (longlong *)0x0;
            local_78 = (undefined1  [16])0x0;
            if (unaff_R15 != (code *)0x0) goto LAB_23e718c0d;
LAB_23e718c1d:
            if ((pcVar12 != (code *)0x0) &&
               (*(longlong *)pcVar12 = *(longlong *)pcVar12 + -1, *(longlong *)pcVar12 == 0)) {
              (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
            }
          }
        }
        local_78._8_8_ = uVar17;
        local_78._0_8_ = uVar10;
        uVar15 = 0xfb;
        pcVar12 = (code *)0x0;
        unaff_R15 = (code *)0x0;
        local_68 = plVar8;
      }
    }
LAB_23e718c4b:
    uVar16 = uVar15;
    if (local_68 != (longlong *)0x0) goto LAB_23e718c54;
  }
  plVar11 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (longlong *)0x0) {
    plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    plVar8 = (longlong *)*DAT_23ed6a4f8;
    *DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = plVar8;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  pcVar5 = _PyRuntime_exref;
  plVar11[2] = 0;
  plVar11[3] = (longlong)plVar4;
  *plVar4 = *plVar4 + 1;
  lVar13 = *(longlong *)(pcVar5 + 0x1f8);
  *(undefined4 *)((longlong)plVar11 + 0x24) = uVar16;
  lVar13 = *(longlong *)(lVar13 + 0x10);
  *(undefined4 *)(plVar11 + 4) = 0xffffffff;
  lVar13 = *(longlong *)(lVar13 + 0x2e8);
  lVar2 = plVar11[-1];
  puVar3 = *(undefined8 **)(lVar13 + 8);
  *puVar3 = plVar11 + -2;
  plVar11[-2] = lVar13;
  plVar11[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar13 + 8) = plVar11 + -2;
LAB_23e718cff:
  local_68 = plVar11;
  FUN_23e8bba40(plVar4,&DAT_23ec5dee6,plVar1,pcVar9,unaff_R15,pcVar12);
  if (DAT_23eedb068 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23eedb068 = (longlong *)0x0;
  }
  lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar13 + 0x28);
  plVar4 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar4 = local_68;
  plVar8[0xf] = 0;
  uVar17 = local_78._8_8_;
  uVar10 = local_78._0_8_;
  local_78 = (undefined1  [16])0x0;
  local_68 = (longlong *)0x0;
  if ((pcVar9 != (code *)0x0) &&
     (*(longlong *)pcVar9 = *(longlong *)pcVar9 + -1, *(longlong *)pcVar9 == 0)) {
    (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
  }
  if ((unaff_R15 != (code *)0x0) &&
     (*(longlong *)unaff_R15 = *(longlong *)unaff_R15 + -1, *(longlong *)unaff_R15 == 0)) {
    (**(code **)(*(longlong *)(unaff_R15 + 8) + 0x30))(unaff_R15);
  }
  if ((pcVar12 != (code *)0x0) &&
     (*(longlong *)pcVar12 = *(longlong *)pcVar12 + -1, *(longlong *)pcVar12 == 0)) {
    (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar10,uVar17,plVar4);
  return (longlong *)0x0;
}
