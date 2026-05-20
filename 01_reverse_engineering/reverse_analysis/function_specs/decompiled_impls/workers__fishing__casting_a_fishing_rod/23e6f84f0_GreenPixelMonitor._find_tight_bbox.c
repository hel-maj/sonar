/* ===== 23e6f84f0 workers.fishing.casting_a_fishin:155 ===== */
/* ghidra_name=FUN_23e6f84f0 entry=23e6f84f0 size=6291 */

code * FUN_23e6f84f0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 auVar8 [16];
  longlong *plVar9;
  char cVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  longlong *plVar16;
  longlong *plVar17;
  code *pcVar18;
  code *pcVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  longlong *local_c0;
  longlong *local_b8;
  longlong *local_b0;
  undefined4 local_a8;
  undefined1 local_98 [16];
  longlong *local_88;
  longlong *local_78;
  longlong *local_70;
  longlong *local_68;
  
  plVar11 = DAT_23eedb1e0;
  plVar1 = (longlong *)param_3[1];
  plVar2 = (longlong *)*param_3;
  local_88 = (longlong *)0x0;
  local_98 = (undefined1  [16])0x0;
  if (DAT_23eedb1e0 == (longlong *)0x0) {
LAB_23e6f8556:
    DAT_23eedb1e0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedb1d8,DAT_23eedb268,0x50);
  }
  else {
    lVar15 = *DAT_23eedb1e0;
    if (1 < lVar15) {
      *DAT_23eedb1e0 = lVar15 + -1;
      goto LAB_23e6f8556;
    }
    if (DAT_23eedb1e0[2] != 0) {
      *DAT_23eedb1e0 = lVar15 + -1;
      if (lVar15 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e6f8556;
    }
  }
  plVar6 = DAT_23eedb1e0;
  lVar15 = *(longlong *)(param_1 + 0x38);
  plVar11 = DAT_23eedb1e0 + 9;
  lVar3 = *(longlong *)(lVar15 + 8);
  DAT_23eedb1e0[0xf] = lVar3;
  *(longlong **)(lVar15 + 8) = plVar11;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  uVar20 = DAT_23eeda4b0;
  *(undefined4 *)(plVar6 + 8) = 0;
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,uVar20);
  if (plVar11 == (longlong *)0x0) {
    local_88 = *(longlong **)(param_1 + 0x70);
    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar14 = (longlong *)0x0;
    pcVar18 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    local_a8 = 0x9e;
    local_b0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e6f8fd0;
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4b0);
  if (plVar12 == (longlong *)0x0) {
    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_88 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar11 = *plVar11 + -1;
    plVar12 = (longlong *)0x0;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
LAB_23e6f9479:
    local_b0 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    pcVar18 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    local_a8 = 0x9e;
    local_b8 = (longlong *)0x0;
    goto LAB_23e6f8fd0;
  }
  plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4c0);
  if (plVar13 == (longlong *)0x0) {
    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_88 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    local_a8 = 0x9e;
    local_c0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    pcVar18 = (code *)0x0;
    goto LAB_23e6f8fd0;
  }
  plVar14 = (longlong *)FUN_23e8c09e0(plVar12,plVar13);
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  pcVar19 = _Py_NoneStruct_exref;
  if (plVar14 == (longlong *)0x0) {
    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_88 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    local_b0 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    pcVar18 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    local_a8 = 0x9e;
    local_b8 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    goto LAB_23e6f8fd0;
  }
  lVar15 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),plVar11,plVar14,_Py_NoneStruct_exref);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  lVar3 = *(longlong *)(param_1 + 0x10);
  plVar11 = *(longlong **)(lVar3 + 0xe20);
  if (plVar11 == (longlong *)0x0) {
    plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
  }
  else {
    lVar4 = plVar11[3];
    *(int *)(lVar3 + 0xebc) = *(int *)(lVar3 + 0xebc) + -1;
    *(longlong *)(lVar3 + 0xe20) = lVar4;
    *plVar11 = 1;
  }
  pcVar18 = _PyRuntime_exref;
  plVar11[4] = 0;
  lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
  lVar4 = plVar11[-1];
  puVar5 = *(undefined8 **)(lVar3 + 8);
  *puVar5 = plVar11 + -2;
  plVar11[-2] = lVar3;
  plVar11[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
  *(longlong **)(lVar3 + 8) = plVar11 + -2;
  uVar20 = DAT_23eeda4a8;
  plVar11[3] = lVar15;
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,uVar20);
  if (plVar12 == (longlong *)0x0) {
    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_88 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4a8);
    if (plVar13 != (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4b8);
      if (plVar14 == (longlong *)0x0) {
        local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_88 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        goto LAB_23e6f93ea;
      }
      plVar16 = (longlong *)FUN_23e8c09e0(plVar13,plVar14);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar16 != (longlong *)0x0) {
        lVar15 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),plVar12,plVar16,pcVar19);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        plVar11[4] = lVar15;
        plVar12 = (longlong *)FUN_23a38cc10(param_1,plVar1,plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar12 == (longlong *)0x0) {
          local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_88 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e6f9479;
        }
        lVar15 = FUN_23e8e1c50();
        if (lVar15 == 0) {
          FUN_23e915740(param_1,local_98,DAT_23eeda460);
          plVar11 = (longlong *)0x0;
        }
        else {
          plVar13 = (longlong *)FUN_23e8bc2f0(lVar15,DAT_23eeda468);
          if (plVar13 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_88 = *(longlong **)(param_1 + 0x70);
            plVar14 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar11 = (longlong *)0x0;
            local_a8 = 0xa0;
            local_b0 = (longlong *)0x0;
            local_c0 = (longlong *)0x0;
            local_b8 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar18 = (code *)0x0;
            goto LAB_23e6f8fd0;
          }
          lVar15 = FUN_23e8e1c50();
          if (lVar15 == 0) {
            FUN_23e915740(param_1,local_98,DAT_23eeda460);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            plVar11 = (longlong *)0x0;
          }
          else {
            plVar14 = (longlong *)FUN_23e8bc2f0(lVar15,DAT_23eeda538);
            if (plVar14 == (longlong *)0x0) {
              local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_88 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              local_b0 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              pcVar18 = (code *)0x0;
              plVar11 = (longlong *)0x0;
              local_c0 = (longlong *)0x0;
              local_a8 = 0xa0;
              local_b8 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              goto LAB_23e6f8fd0;
            }
            *(undefined4 *)(plVar6 + 5) = 0xa0;
            local_78 = plVar12;
            local_70 = plVar14;
            plVar11 = (longlong *)FUN_23e94ed00(param_1,plVar13,&local_78);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (plVar11 != (longlong *)0x0) {
              lVar15 = FUN_23e8e1c50();
              if (lVar15 == 0) {
                FUN_23e915740(param_1,local_98,DAT_23eeda460);
                plVar13 = (longlong *)0x0;
LAB_23e6f96cf:
                local_b0 = (longlong *)0x0;
                plVar14 = (longlong *)0x0;
                pcVar18 = (code *)0x0;
                local_a8 = 0xa1;
                local_c0 = (longlong *)0x0;
                local_b8 = (longlong *)0x0;
                goto LAB_23e6f8fd0;
              }
              plVar14 = (longlong *)FUN_23e8bc2f0(lVar15,DAT_23eeda540);
              if (plVar14 == (longlong *)0x0) {
                local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_88 = *(longlong **)(param_1 + 0x70);
                plVar14 = (longlong *)0x0;
                pcVar18 = (code *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plVar13 = (longlong *)0x0;
                local_a8 = 0xa1;
                local_b0 = (longlong *)0x0;
                local_c0 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                local_b8 = (longlong *)0x0;
                goto LAB_23e6f8fd0;
              }
              plVar16 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda548);
              if (plVar16 == (longlong *)0x0) {
                local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_88 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                lVar15 = *plVar14;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar14 = lVar15 + -1;
                if (lVar15 + -1 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                local_b0 = (longlong *)0x0;
                plVar14 = (longlong *)0x0;
                plVar13 = (longlong *)0x0;
                local_a8 = 0xa1;
                local_c0 = (longlong *)0x0;
                local_b8 = (longlong *)0x0;
                pcVar18 = (code *)0x0;
                goto LAB_23e6f8fd0;
              }
              plVar17 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda550);
              if (plVar17 == (longlong *)0x0) {
                local_88 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                lVar15 = *plVar14;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar14 = lVar15 + -1;
                if (lVar15 + -1 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                plVar14 = (longlong *)0x0;
                pcVar18 = (code *)0x0;
                plVar13 = (longlong *)0x0;
                local_b0 = (longlong *)0x0;
                local_a8 = 0xa1;
                local_b8 = (longlong *)0x0;
                local_c0 = (longlong *)0x0;
                goto LAB_23e6f8fd0;
              }
              *(undefined4 *)(plVar6 + 5) = 0xa1;
              local_78 = plVar11;
              local_70 = plVar16;
              local_68 = plVar17;
              plVar13 = (longlong *)FUN_23e956150(param_1,plVar14,&local_78);
              lVar15 = *plVar14;
              *plVar14 = lVar15 + -1;
              if (lVar15 + -1 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              lVar15 = *plVar17;
              *plVar17 = lVar15 + -1;
              if (lVar15 + -1 == 0) {
                (**(code **)(plVar17[1] + 0x30))();
              }
              if (plVar13 == (longlong *)0x0) {
                local_88 = *(longlong **)(param_1 + 0x70);
                local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e6f96cf;
              }
              lVar15 = FUN_23e8e1c50();
              if (lVar15 == 0) {
                FUN_23e915740(param_1,local_98,DAT_23eeda460);
                pcVar18 = (code *)0x0;
              }
              else {
                *(undefined4 *)(plVar6 + 5) = 0xa2;
                pcVar18 = (code *)FUN_23e915840(param_1,lVar15,DAT_23eeda568,plVar13);
                if (pcVar18 != (code *)0x0) {
                  if (pcVar18 == pcVar19) {
                    *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
                    plVar14 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
LAB_23e6f8d10:
                    lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                    plVar6 = *(longlong **)(lVar15 + 0x28);
                    plVar16 = (longlong *)plVar6[2];
                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                         *(undefined8 *)(lVar15 + 0x30);
                    *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                    if (plVar16 != (longlong *)0x0) {
                      plVar6[2] = 0;
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        (**(code **)(plVar16[1] + 0x30))();
                      }
                    }
                    *plVar6 = *plVar6 + -1;
                    if (*plVar6 == 0) {
                      (**(code **)(plVar6[1] + 0x30))(plVar6);
                    }
                    plVar6[0xf] = 0;
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
                    if (*(longlong *)pcVar18 == 0) {
                      (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
                    }
                    if ((local_b8 != (longlong *)0x0) &&
                       (lVar15 = *local_b8, *local_b8 = lVar15 + -1, lVar15 + -1 == 0)) {
                      (**(code **)(local_b8[1] + 0x30))(local_b8);
                    }
                    if ((local_c0 != (longlong *)0x0) &&
                       (lVar15 = *local_c0, *local_c0 = lVar15 + -1, lVar15 + -1 == 0)) {
                      (**(code **)(local_c0[1] + 0x30))(local_c0);
                    }
                    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    if ((local_b0 != (longlong *)0x0) &&
                       (lVar15 = *local_b0, *local_b0 = lVar15 + -1, lVar15 + -1 == 0)) {
                      (**(code **)(local_b0[1] + 0x30))(local_b0);
                    }
                    *plVar2 = *plVar2 + -1;
                    if (*plVar2 == 0) {
                      (**(code **)(plVar2[1] + 0x30))(plVar2);
                    }
                    lVar15 = *plVar1;
                    *plVar1 = lVar15 + -1;
                    if (lVar15 + -1 != 0) {
                      return pcVar19;
                    }
                    (**(code **)(plVar1[1] + 0x30))(plVar1);
                    return pcVar19;
                  }
                  lVar15 = FUN_23e8e1c50();
                  if (lVar15 == 0) {
                    FUN_23e915740(param_1,local_98,DAT_23eeda460);
                    plVar16 = local_88;
                    uVar20 = local_98._0_8_;
                    uVar21 = local_98._8_8_;
                  }
                  else {
                    *(undefined4 *)(plVar6 + 5) = 0xa5;
                    plVar14 = (longlong *)FUN_23e915840(param_1,lVar15,DAT_23eeda570,pcVar18);
                    if (plVar14 != (longlong *)0x0) {
                      plVar17 = (longlong *)FUN_23a388310(plVar14);
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      if (plVar17 != (longlong *)0x0) {
                        local_b8 = (longlong *)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                        if ((local_b8 == (longlong *)0x0) &&
                           (local_b8 = (longlong *)FUN_23a3c1b70(param_1),
                           local_b8 == (longlong *)0x0)) {
                          plVar14 = (longlong *)0x0;
                          local_b0 = (longlong *)0x0;
                          local_c0 = (longlong *)0x0;
                        }
                        else {
                          local_c0 = (longlong *)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                          if ((local_c0 == (longlong *)0x0) &&
                             (local_c0 = (longlong *)FUN_23a3c1b70(param_1,local_98,1,4),
                             local_c0 == (longlong *)0x0)) {
                            plVar14 = (longlong *)0x0;
                            local_b0 = (longlong *)0x0;
                          }
                          else {
                            plVar14 = (longlong *)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                            if ((plVar14 == (longlong *)0x0) &&
                               (plVar14 = (longlong *)FUN_23a3c1b70(param_1,local_98,2,4),
                               plVar14 == (longlong *)0x0)) {
                              local_b0 = (longlong *)0x0;
                            }
                            else {
                              local_b0 = (longlong *)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                              if (((local_b0 != (longlong *)0x0) ||
                                  (local_b0 = (longlong *)FUN_23a3c1b70(param_1,local_98,3,4),
                                  local_b0 != (longlong *)0x0)) &&
                                 (cVar10 = FUN_23a3884a0(param_1,local_98,plVar17,4), cVar10 != '\0'
                                 )) {
                                *plVar17 = *plVar17 + -1;
                                if (*plVar17 == 0) {
                                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                                }
                                if (*local_b8 == 0) {
                                  (**(code **)(local_b8[1] + 0x30))();
                                }
                                if (*local_c0 == 0) {
                                  (**(code **)(local_c0[1] + 0x30))();
                                }
                                if (*plVar14 == 0) {
                                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                                }
                                if (*local_b0 == 0) {
                                  (**(code **)(local_b0[1] + 0x30))();
                                }
                                plVar16 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4a8);
                                if (plVar16 != (longlong *)0x0) {
                                  lVar15 = FUN_23e8c09e0(plVar16,local_b8);
                                  *plVar16 = *plVar16 + -1;
                                  if (*plVar16 == 0) {
                                    (**(code **)(plVar16[1] + 0x30))();
                                  }
                                  if (lVar15 != 0) {
                                    lVar3 = *(longlong *)(param_1 + 0x10);
                                    pcVar19 = *(code **)(lVar3 + 0xe30);
                                    if (pcVar19 == (code *)0x0) {
                                      pcVar19 = (code *)FUN_23e916a20(PyTuple_Type_exref,4);
                                    }
                                    else {
                                      lVar4 = *(longlong *)(pcVar19 + 0x18);
                                      *(int *)(lVar3 + 0xec4) = *(int *)(lVar3 + 0xec4) + -1;
                                      *(longlong *)(lVar3 + 0xe30) = lVar4;
                                      *(longlong *)pcVar19 = 1;
                                    }
                                    pcVar7 = _PyRuntime_exref;
                                    *(longlong *)(pcVar19 + 0x30) = 0;
                                    *(undefined1 (*) [16])(pcVar19 + 0x20) = (undefined1  [16])0x0;
                                    lVar3 = *(longlong *)
                                             (*(longlong *)(*(longlong *)(pcVar7 + 0x1f8) + 0x10) +
                                             0x2e8);
                                    lVar4 = *(longlong *)(pcVar19 + -8);
                                    puVar5 = *(undefined8 **)(lVar3 + 8);
                                    *puVar5 = pcVar19 + -0x10;
                                    *(longlong *)(pcVar19 + -0x10) = lVar3;
                                    *(ulonglong *)(pcVar19 + -8) =
                                         (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
                                    *(code **)(lVar3 + 8) = pcVar19 + -0x10;
                                    uVar20 = DAT_23eeda4b0;
                                    *(longlong *)(pcVar19 + 0x18) = lVar15;
                                    plVar16 = (longlong *)FUN_23e8bc2f0(plVar2,uVar20);
                                    if (plVar16 != (longlong *)0x0) {
                                      lVar15 = FUN_23e8c09e0(plVar16,local_c0);
                                      *plVar16 = *plVar16 + -1;
                                      if (*plVar16 == 0) {
                                        (**(code **)(plVar16[1] + 0x30))();
                                      }
                                      if (lVar15 != 0) {
                                        *(longlong *)(pcVar19 + 0x20) = lVar15;
                                        *plVar14 = *plVar14 + 1;
                                        *(longlong **)(pcVar19 + 0x28) = plVar14;
                                        *local_b0 = *local_b0 + 1;
                                        *(longlong **)(pcVar19 + 0x30) = local_b0;
                                        goto LAB_23e6f8d10;
                                      }
                                    }
                                    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    local_88 = *(longlong **)(param_1 + 0x70);
                                    local_a8 = 0xa6;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
                                    if (*(longlong *)pcVar19 == 0) {
                                      FUN_23a334bc0(pcVar19);
                                      local_a8 = 0xa6;
                                    }
                                    goto LAB_23e6f8fd0;
                                  }
                                }
                                local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                local_88 = *(longlong **)(param_1 + 0x70);
                                local_a8 = 0xa6;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e6f8fd0;
                              }
                            }
                          }
                        }
                        plVar16 = local_88;
                        uVar20 = local_98._0_8_;
                        uVar21 = local_98._8_8_;
                        local_88 = (longlong *)0x0;
                        local_98 = (undefined1  [16])0x0;
                        *plVar17 = *plVar17 + -1;
                        if (*plVar17 == 0) {
                          (**(code **)(plVar17[1] + 0x30))(plVar17);
                        }
                        local_88 = (longlong *)0x0;
                        local_98 = (undefined1  [16])0x0;
                        if ((local_b8 != (longlong *)0x0) &&
                           (lVar15 = *local_b8, *local_b8 = lVar15 + -1, lVar15 + -1 == 0)) {
                          (**(code **)(local_b8[1] + 0x30))(local_b8);
                        }
                        if ((local_c0 != (longlong *)0x0) &&
                           (lVar15 = *local_c0, *local_c0 = lVar15 + -1, lVar15 + -1 == 0)) {
                          (**(code **)(local_c0[1] + 0x30))(local_c0);
                        }
                        if ((plVar14 != (longlong *)0x0) &&
                           (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                          (**(code **)(plVar14[1] + 0x30))(plVar14);
                        }
                        if ((local_b0 != (longlong *)0x0) &&
                           (lVar15 = *local_b0, *local_b0 = lVar15 + -1, lVar15 + -1 == 0)) {
                          (**(code **)(local_b0[1] + 0x30))(local_b0);
                        }
                        goto LAB_23e6f9ba5;
                      }
                    }
                    uVar20 = *(undefined8 *)(param_1 + 0x60);
                    plVar16 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar21 = *(undefined8 *)(param_1 + 0x68);
                  }
LAB_23e6f9ba5:
                  local_a8 = 0xa5;
                  plVar14 = (longlong *)0x0;
                  local_b0 = (longlong *)0x0;
                  local_c0 = (longlong *)0x0;
                  local_b8 = (longlong *)0x0;
                  local_98._8_8_ = uVar21;
                  local_98._0_8_ = uVar20;
                  local_88 = plVar16;
                  goto LAB_23e6f8fd0;
                }
                local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_88 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              local_b0 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              local_a8 = 0xa2;
              local_c0 = (longlong *)0x0;
              local_b8 = (longlong *)0x0;
              goto LAB_23e6f8fd0;
            }
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_88 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
        }
        plVar14 = (longlong *)0x0;
        pcVar18 = (code *)0x0;
        plVar13 = (longlong *)0x0;
        local_a8 = 0xa0;
        local_b0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        goto LAB_23e6f8fd0;
      }
    }
    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_88 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
  }
LAB_23e6f93ea:
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  local_b0 = (longlong *)0x0;
  plVar14 = (longlong *)0x0;
  pcVar18 = (code *)0x0;
  plVar11 = (longlong *)0x0;
  local_c0 = (longlong *)0x0;
  local_a8 = 0x9f;
  plVar13 = (longlong *)0x0;
  plVar12 = (longlong *)0x0;
  local_b8 = (longlong *)0x0;
LAB_23e6f8fd0:
  plVar17 = local_88;
  plVar16 = DAT_23ed6a4f8;
  if (local_88 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar17 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar17;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar16[2] = 0;
    plVar16[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    *(undefined4 *)((longlong)plVar16 + 0x24) = local_a8;
    pcVar19 = _PyRuntime_exref;
    *(undefined4 *)(plVar16 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar19 + 0x1f8) + 0x10) + 0x2e8);
    lVar3 = plVar16[-1];
    puVar5 = *(undefined8 **)(lVar15 + 8);
    *puVar5 = plVar16 + -2;
    plVar16[-2] = lVar15;
    plVar16[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar15 + 8) = plVar16 + -2;
    plVar17 = plVar16;
    if ((local_88 != (longlong *)0x0) && (*local_88 = *local_88 + -1, *local_88 == 0)) {
      (**(code **)(local_88[1] + 0x30))(local_88);
    }
  }
  else if ((longlong *)local_88[3] != plVar6) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar9 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar9;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar16[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    *(undefined4 *)((longlong)plVar16 + 0x24) = local_a8;
    pcVar19 = _PyRuntime_exref;
    *(undefined4 *)(plVar16 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar19 + 0x1f8) + 0x10) + 0x2e8);
    lVar3 = plVar16[-1];
    puVar5 = *(undefined8 **)(lVar15 + 8);
    *puVar5 = plVar16 + -2;
    plVar16[-2] = lVar15;
    plVar16[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar15 + 8) = plVar16 + -2;
    plVar16[2] = (longlong)plVar17;
    *plVar17 = *plVar17 + 1;
    plVar17 = plVar16;
    if ((local_88 != (longlong *)0x0) && (*local_88 = *local_88 + -1, *local_88 == 0)) {
      (**(code **)(local_88[1] + 0x30))();
    }
  }
  local_88 = plVar17;
  FUN_23e8bba40(plVar6,"oooooooooo",plVar2,plVar1,plVar12,plVar11,plVar13,pcVar18,local_b8,local_c0,
                plVar14,local_b0);
  if (DAT_23eedb1e0 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    DAT_23eedb1e0 = (longlong *)0x0;
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar15 + 0x28);
  plVar16 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar16 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar16 = local_88;
  auVar8 = local_98;
  plVar6[0xf] = 0;
  local_98 = (undefined1  [16])0x0;
  local_88 = (longlong *)0x0;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((pcVar18 != (code *)0x0) &&
     (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
  }
  if ((local_b8 != (longlong *)0x0) &&
     (lVar15 = *local_b8, *local_b8 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_b8[1] + 0x30))(local_b8);
  }
  if ((local_c0 != (longlong *)0x0) &&
     (lVar15 = *local_c0, *local_c0 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_c0[1] + 0x30))(local_c0);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((local_b0 != (longlong *)0x0) &&
     (lVar15 = *local_b0, *local_b0 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_b0[1] + 0x30))(local_b0);
  }
  *plVar2 = *plVar2 + -1;
  local_98 = auVar8;
  local_88 = plVar16;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar15 = *plVar1;
  *plVar1 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_98._0_8_,local_98._8_8_,local_88);
  return (code *)0x0;
}
